#include "client.h"

///@brief Constructor Client
///@details Instanciado com o status como busy
Client::Client(QObject *parent, bool busy, int id) :
    QObject(parent)
{
    this->busy = busy;
    this->myId = id;
}

///@brief Trata a conexão no Socket
///@param Descriptor File Descriptor
void Client::setSocket(qintptr Descriptor)
{
    socket = new QTcpSocket(this);

    qDebug() << "Socket criado";

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    socket->setSocketDescriptor(Descriptor);

    qDebug() << " Client conectado em " << Descriptor;
}

void Client::setAracne(Aracne *aracne){
    this->aracne = aracne;
}


void Client::connected()
{
    qDebug() << "Client conectado";
}


void Client::disconnected()
{
    qDebug() << "Client desconectado";
}

void Client::readyRead()
{
    qDebug() << Q_FUNC_INFO << "Socket::readyRead()";

    QByteArray request = socket->readAll();

    qDebug() << Q_FUNC_INFO << request;

    emit new_request(request, this->myId);
}

///@brief Sinal de enviar Request
///@param request String da requisição
///@param clientId ID do Client
///@details Cria o socket para fazer a conexão do Client para enviar a requisição e aguarda pela resposta
void Client::send_request(QByteArray request, int clientId){
    if(this->myId == clientId){
        Socket *socket = new Socket(request, clientId);

        connect(socket, SIGNAL(new_reply(QByteArray, int)), this->aracne, SLOT(new_reply(QByteArray, int)));

        socket->start();
    }
}

///@brief Sinal de enviar Reply
///@param reply String da resposta
///@param clientId ID do Client
///@details Envia a resposta de volta e fecha conexão
void Client::send_reply(QByteArray reply, int clientId){
    if(clientId == this->myId){
        socket->write(reply);
        socket->disconnectFromHost();
    }
}
