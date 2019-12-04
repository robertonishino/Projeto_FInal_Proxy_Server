#ifndef ARACNE_H
#define ARACNE_H

#include <QDebug>
#include <QMainWindow>
#include "string"
#include "list"
#include "QListWidgetItem"
#include <queue>

namespace Ui {
class Aracne;
}

class Aracne : public QMainWindow{
    Q_OBJECT

public:
    explicit Aracne(QWidget *parent = nullptr);
    ~Aracne();
    void setServerOff();
    void setServerOn();

private slots:

    void on_requestButton_clicked();
    void on_replyButton_clicked();
    void on_startServerButton_clicked();
    void on_stopServerButton_clicked();

public slots:
    void new_request(QByteArray, int);
    void new_reply(QByteArray, int);

private:
    Ui::Aracne *ui;
    std::queue<int> requestsId;
    std::queue<int> repliesId;

signals:
    void send_request(QByteArray, int);
    void send_reply(QByteArray, int);
    void turn_on();
    void turn_off();
    void set_mode(QString);
};

#endif // ARACNE_H
