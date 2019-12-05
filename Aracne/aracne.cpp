#include "aracne.h"
#include "ui_aracne.h"
#include <iostream>


///@brief Abre a tela com valores default e server offline
///@param parent Tela de UI
///@param ui Aracne
Aracne::Aracne(QWidget *parent) : QMainWindow(parent), ui(new Ui::Aracne) {
    ui->setupUi(this);
    this->ui->serverLabel->setText("Server Offline");
    this->ui->serverLabel->setStyleSheet("QLabel{color:red;}");

    this->ui->startServerButton->setDisabled(false);
    this->ui->stopServerButton->setDisabled(true);
}

///@brief Destructor Aracne
Aracne::~Aracne(){
    delete ui;
}

///@brief Trata nova requisição e envia as informações para o Client
///@param clientId ID do host
///@param request String da requisição
///@details Cria uma nova requisição, adiciona na lista de requisições, permite edição e envia para o Client
void Aracne::new_request(QByteArray request, int clientId){
    QListWidgetItem *item = new QListWidgetItem(request);
    item->setFlags (item->flags () | Qt::ItemIsEditable);
    item->setSizeHint(QSize(item->sizeHint().width(), 250));
    this->ui->requestsWidget->addItem(item);
    this->requestsId.push(clientId);
}

///@brief Trata nova resposta e salva as informações para o Client
///@param reply String da resposta
///@param clientID ID do Client
///@details Cria uma nova resposta, adiciona na lista de respostas, permite edição e salva para uso no Client
void Aracne::new_reply(QByteArray reply, int clientId){
    QListWidgetItem *item = new QListWidgetItem(reply);
    item->setFlags (item->flags () | Qt::ItemIsEditable);
    item->setSizeHint(QSize(item->sizeHint().width(), 250));
    this->ui->repliesWidget->addItem(item);
    this->repliesId.push(clientId);
}

///@brief Funcionalidade de apertar o botão request na UI
///@details Trata a primeira requisição na lista de requisições, pega o ID e envia para o Client
void Aracne::on_requestButton_clicked(){
    QListWidgetItem *item = this->ui->requestsWidget->takeItem(0);
    if(item == nullptr)
        return;
    int clientId = this->requestsId.front();
    this->requestsId.pop();
    emit send_request(QByteArray(item->text().toStdString().c_str()), clientId);
}

///@brief Funcionalidade de apertar o botão reply na UI
///@details Trata a primeira resposta na lista de respostas, pega o ID e envia para o Client
void Aracne::on_replyButton_clicked(){
    QListWidgetItem *item = this->ui->repliesWidget->takeItem(0);
    if(item == nullptr)
        return;
    int clientId = this->repliesId.front();
    this->repliesId.pop();
    emit send_reply(QByteArray(item->text().toStdString().c_str()), clientId);
}

///@brief Muda os status do servidor para ligado
///@details Muda o label para Server Online, a cor para verde e liga o servidor Proxy
void Aracne::setServerOn(){
    this->ui->serverLabel->setText("Server Online");
    this->ui->serverLabel->setStyleSheet("QLabel{color:green;}");

    this->ui->startServerButton->setDisabled(true);
    this->ui->stopServerButton->setDisabled(false);
}

///@brief Muda os status do servidor para desligado
///@details Muda o label para Server Offline, muda a cor para vermelho e desliga o servidor Proxy
void Aracne::setServerOff(){
    this->ui->serverLabel->setText("Server Offline");
    this->ui->serverLabel->setStyleSheet("QLabel{color:red;}");

    this->ui->startServerButton->setDisabled(false);
    this->ui->stopServerButton->setDisabled(true);
}

///@brief Liga o servidor Proxy
void Aracne::on_startServerButton_clicked(){
    emit turn_on();
    this->setServerOn();
}

///@brief Desliga o servidor Proxy
void Aracne::on_stopServerButton_clicked(){
    emit turn_off();
    this->setServerOff();
}
