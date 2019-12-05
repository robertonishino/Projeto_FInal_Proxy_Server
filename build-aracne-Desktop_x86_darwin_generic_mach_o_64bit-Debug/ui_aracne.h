/********************************************************************************
** Form generated from reading UI file 'aracne.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARACNE_H
#define UI_ARACNE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Aracne
{
public:
    QWidget *centralWidget;
    QPushButton *spiderButton;
    QPushButton *dumpButton;
    QListWidget *requestsWidget;
    QListWidget *repliesWidget;
    QPushButton *requestButton;
    QPushButton *replyButton;
    QPushButton *startServerButton;
    QPushButton *stopServerButton;
    QLabel *serverLabel;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *Aracne)
    {
        if (Aracne->objectName().isEmpty())
            Aracne->setObjectName(QString::fromUtf8("Aracne"));
        Aracne->resize(1291, 720);
        centralWidget = new QWidget(Aracne);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        spiderButton = new QPushButton(centralWidget);
        spiderButton->setObjectName(QString::fromUtf8("spiderButton"));
        spiderButton->setGeometry(QRect(1090, 10, 89, 25));
        dumpButton = new QPushButton(centralWidget);
        dumpButton->setObjectName(QString::fromUtf8("dumpButton"));
        dumpButton->setGeometry(QRect(1180, 10, 89, 25));
        requestsWidget = new QListWidget(centralWidget);
        requestsWidget->setObjectName(QString::fromUtf8("requestsWidget"));
        requestsWidget->setGeometry(QRect(20, 40, 621, 621));
        requestsWidget->setMaximumSize(QSize(1250, 1250));
        requestsWidget->setAutoScroll(true);
        requestsWidget->setAlternatingRowColors(true);
        requestsWidget->setTextElideMode(Qt::ElideLeft);
        requestsWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        repliesWidget = new QListWidget(centralWidget);
        repliesWidget->setObjectName(QString::fromUtf8("repliesWidget"));
        repliesWidget->setGeometry(QRect(650, 40, 621, 620));
        repliesWidget->setMaximumSize(QSize(1250, 620));
        requestButton = new QPushButton(centralWidget);
        requestButton->setObjectName(QString::fromUtf8("requestButton"));
        requestButton->setGeometry(QRect(20, 10, 93, 28));
        replyButton = new QPushButton(centralWidget);
        replyButton->setObjectName(QString::fromUtf8("replyButton"));
        replyButton->setGeometry(QRect(650, 10, 93, 28));
        startServerButton = new QPushButton(centralWidget);
        startServerButton->setObjectName(QString::fromUtf8("startServerButton"));
        startServerButton->setGeometry(QRect(20, 670, 93, 28));
        stopServerButton = new QPushButton(centralWidget);
        stopServerButton->setObjectName(QString::fromUtf8("stopServerButton"));
        stopServerButton->setGeometry(QRect(110, 670, 93, 28));
        serverLabel = new QLabel(centralWidget);
        serverLabel->setObjectName(QString::fromUtf8("serverLabel"));
        serverLabel->setGeometry(QRect(600, 670, 101, 16));
        QFont font;
        font.setPointSize(12);
        serverLabel->setFont(font);
        Aracne->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Aracne);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1291, 22));
        Aracne->setMenuBar(menuBar);

        retranslateUi(Aracne);

        QMetaObject::connectSlotsByName(Aracne);
    } // setupUi

    void retranslateUi(QMainWindow *Aracne)
    {
        Aracne->setWindowTitle(QApplication::translate("Aracne", "Aracne", nullptr));
        spiderButton->setText(QApplication::translate("Aracne", "Spider", nullptr));
        dumpButton->setText(QApplication::translate("Aracne", "Dump", nullptr));
        requestButton->setText(QApplication::translate("Aracne", "Request", nullptr));
        replyButton->setText(QApplication::translate("Aracne", "Reply", nullptr));
        startServerButton->setText(QApplication::translate("Aracne", "Start Server", nullptr));
        stopServerButton->setText(QApplication::translate("Aracne", "Stop Server", nullptr));
        serverLabel->setText(QApplication::translate("Aracne", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Aracne: public Ui_Aracne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARACNE_H
