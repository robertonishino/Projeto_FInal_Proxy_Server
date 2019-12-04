#include "proxy.h"

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

void Proxy::incomingConnection(qintptr socketDescriptor){
    if(!this->serverOn) return;
    else if(this->mode == "standard") this->standardMode(socketDescriptor);
    else return;
}

void Proxy::standardMode(qintptr socketDescriptor){
    Client *client = new Client(this, busy, this->clientId++);

    connect(client, SIGNAL(new_request(QByteArray, int)), this->_aracne, SLOT(new_request(QByteArray, int)));
    connect(this->_aracne, SIGNAL(send_reply(QByteArray, int)), client, SLOT(send_reply(QByteArray, int)));
    connect(this->_aracne, SIGNAL(send_request(QByteArray, int)), client, SLOT(send_request(QByteArray, int)));

    client->setAracne(this->_aracne);
    client->setSocket(socketDescriptor);
}
