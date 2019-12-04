#ifndef CLIENT_H
#define CLIENT_H


#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QThreadPool>
#include "socket.h"
#include "aracne.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr, bool busy = false, int id = 0);
    void setSocket(qintptr Descriptor);
    void setAracne(Aracne *aracne);

signals:
    void new_request(QByteArray, int);

public slots:
    void connected();
    void disconnected();
    void readyRead();
    void send_request(QByteArray, int);
    void send_reply(QByteArray, int);

private:
    QTcpSocket *socket;
    bool busy;
    int myId;
    Aracne *aracne;
};

#endif
