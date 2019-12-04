#include "aracne.h"
#include "ui_aracne.h"
#include <iostream>

Aracne::Aracne(QWidget *parent) : QMainWindow(parent), ui(new Ui::Aracne) {
    ui->setupUi(this);
    this->ui->serverLabel->setText("Server Offline");
    this->ui->serverLabel->setStyleSheet("QLabel{color:red;}");

    this->ui->startServerButton->setDisabled(false);
    this->ui->stopServerButton->setDisabled(true);
}

Aracne::~Aracne(){
    delete ui;
}

void Aracne::new_request(QByteArray request, int clientId){
    QListWidgetItem *item = new QListWidgetItem(request);
    item->setFlags (item->flags () | Qt::ItemIsEditable);
    item->setSizeHint(QSize(item->sizeHint().width(), 250));
    this->ui->requestsWidget->addItem(item);
    this->requestsId.push(clientId);
}

void Aracne::new_reply(QByteArray reply, int clientId){
    QListWidgetItem *item = new QListWidgetItem(reply);
    item->setFlags (item->flags () | Qt::ItemIsEditable);
    item->setSizeHint(QSize(item->sizeHint().width(), 250));
    this->ui->repliesWidget->addItem(item);
    this->repliesId.push(clientId);
}

void Aracne::on_requestButton_clicked(){
    QListWidgetItem *item = this->ui->requestsWidget->takeItem(0);
    if(item == nullptr)
        return;
    int clientId = this->requestsId.front();
    this->requestsId.pop();
    emit send_request(QByteArray(item->text().toStdString().c_str()), clientId);
}

void Aracne::on_replyButton_clicked(){
    QListWidgetItem *item = this->ui->repliesWidget->takeItem(0);
    if(item == nullptr)
        return;
    int clientId = this->repliesId.front();
    this->repliesId.pop();
    emit send_reply(QByteArray(item->text().toStdString().c_str()), clientId);
}

void Aracne::setServerOn(){
    this->ui->serverLabel->setText("Server Online");
    this->ui->serverLabel->setStyleSheet("QLabel{color:green;}");

    this->ui->startServerButton->setDisabled(true);
    this->ui->stopServerButton->setDisabled(false);
}

void Aracne::setServerOff(){
    this->ui->serverLabel->setText("Server Offline");
    this->ui->serverLabel->setStyleSheet("QLabel{color:red;}");

    this->ui->startServerButton->setDisabled(false);
    this->ui->stopServerButton->setDisabled(true);
}

void Aracne::on_startServerButton_clicked(){
    emit turn_on();
    this->setServerOn();
}

void Aracne::on_stopServerButton_clicked(){
    emit turn_off();
    this->setServerOff();
}
