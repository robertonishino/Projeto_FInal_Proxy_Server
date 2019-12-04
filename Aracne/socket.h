#ifndef SOCKET_H
#define SOCKET_H

#include "aracne.h"
#include <QtCore>
#include <QtNetwork>
#include <QByteArray>
#include "httpparser.h"

class Socket : public QObject
{
    Q_OBJECT
public:
    explicit Socket(QByteArray request = nullptr, int clientId = 0);
    void start();

signals:
    void new_reply(QByteArray, int);

public slots:
    void connected();
    void disconnected();

private:
    QTcpSocket *socket;
    QByteArray request;
    QByteArray originalRequest;
    QByteArray reply;
    Aracne *aracne;
    QTimer *timer = nullptr;
    int myId = 0;
};

#endif // SOCKET_H
