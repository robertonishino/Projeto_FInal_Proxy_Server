#ifndef PROXY_H
#define PROXY_H

#include "aracne.h"
#include "client.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>

class Proxy : public QTcpServer
{
    Q_OBJECT
public:
    Proxy(QObject *parent = nullptr, Aracne *aracne = nullptr, unsigned short port = 8228);
    void start();

public slots:
    void turn_on();
    void turn_off();
    void set_mode(QString);

private:
    unsigned short _port;
    Aracne *_aracne;
    bool busy = false;
    int clientId = 0;
    bool serverOn = false;
    QString mode = "standard";
    void standardMode(qintptr socketDescriptor);

protected:
    void incomingConnection(qintptr socketDescriptor) Q_DECL_OVERRIDE;

};

#endif // PROXY_H
