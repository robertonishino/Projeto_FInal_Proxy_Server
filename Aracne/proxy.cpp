#include "proxy.h"


///@brief Constructor Proxy
///@param port Porta para o Proxy escutar
Proxy::Proxy(QObject *parent, Aracne *aracne, unsigned short port) :
    QTcpServer (parent)
{
    this->_aracne = aracne;
    this->_port = port;
    connect(this->_aracne, SIGNAL(turn_on()), this, SLOT(turn_on()));
    connect(this->_aracne, SIGNAL(turn_off()), this, SLOT(turn_off()));
}

void Proxy::start(){
    if(!listen(QHostAddress::Any, this->_port)){
        qDebug() << "Server could not start";
    } else{
        qDebug() << "Server started on port " << this->_port;
    }
}

void Proxy::turn_on(){
    this->serverOn = true;
}

///@brief Seta o modo do Proxy para Standard
///@details Futuramente haverá outros modos como o Spider por exemplo
void Proxy::set_mode(QString mode){
    if(mode != "standard"){
        qDebug() << "Incorrect mode: " << mode;
        return;
    }
    qDebug() << "Changing mode: " << mode;
    this->mode = mode;
}

void Proxy::turn_off(){
    this->serverOn = false;
}

///@brief Trata conexão vindo do Socket
///@param socketDescriptor File Descriptor
void Proxy::incomingConnection(qintptr socketDescriptor){
    if(!this->serverOn) return;
    else if(this->mode == "standard") this->standardMode(socketDescriptor);
    else return;
}

///@brief Instancia novo Client para lidar com a conexão
///@details Trata a conexão, podendo ser envio de requisição, envio de resposta e chegada de nova requisição
void Proxy::standardMode(qintptr socketDescriptor){
    Client *client = new Client(this, busy, this->clientId++);

    connect(client, SIGNAL(new_request(QByteArray, int)), this->_aracne, SLOT(new_request(QByteArray, int)));
    connect(this->_aracne, SIGNAL(send_reply(QByteArray, int)), client, SLOT(send_reply(QByteArray, int)));
    connect(this->_aracne, SIGNAL(send_request(QByteArray, int)), client, SLOT(send_request(QByteArray, int)));

    client->setAracne(this->_aracne);
    client->setSocket(socketDescriptor);
}
