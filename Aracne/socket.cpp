#include "socket.h"


///@brief Constructor do Socket
Socket::Socket(QByteArray request, int clientId) {
    this->myId = clientId;
    this->request = request;
    this->originalRequest = request;
    QThreadPool::globalInstance()->setMaxThreadCount(5);
}

///@brief Faz a conexão com o host
///@details Usa o Parser para os GET na requisição e prepara a conexão com o host
void Socket::start(){
    qDebug() << Q_FUNC_INFO << "Starting thread for client " << this->myId;
    qDebug() << Q_FUNC_INFO << "Request: " << this->request;

    this->socket = new QTcpSocket(this);

    connect(this->socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(this->socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    qDebug() << Q_FUNC_INFO << "Conectando...";

    HttpParser parser;

    parser.parseRequest(this->request);

    char hostname[32];
    strcpy(hostname, parser.getHostname().toStdString().c_str());

    qDebug() << Q_FUNC_INFO << "Hostname: " << hostname;
    this->socket->connectToHost(hostname, 80);
}

///@brief Pega a reply do host e fecha a conexão
void Socket::connected(){
    qDebug() << "Conectado";

    this->socket->write(this->originalRequest);
    while(this->socket->waitForReadyRead(3000)){
        while(this->socket->bytesAvailable() > 0){
            this->reply.append(this->socket->readAll());
            this->socket->flush();
        }
    }

    qDebug() << this->reply;
    this->socket->disconnectFromHost();
    this->socket->deleteLater();
}

///@brief Envia a resposta para ser tratada
void Socket::disconnected(){
    qDebug() << "Desconectado";
    emit new_reply(this->reply, this->myId);
}
