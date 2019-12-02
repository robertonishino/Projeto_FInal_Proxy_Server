/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *DumpButton;
    QPushButton *SpiderButton;
    QPushButton *RequestButton;
    QPushButton *ReplyButton;
    QPushButton *StarButton;
    QPushButton *StopButton;
    QListWidget *RepliesWidget;
    QListWidget *RequestsWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(765, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        DumpButton = new QPushButton(centralwidget);
        DumpButton->setObjectName(QString::fromUtf8("DumpButton"));
        DumpButton->setGeometry(QRect(630, 520, 112, 32));
        SpiderButton = new QPushButton(centralwidget);
        SpiderButton->setObjectName(QString::fromUtf8("SpiderButton"));
        SpiderButton->setGeometry(QRect(510, 520, 112, 32));
        RequestButton = new QPushButton(centralwidget);
        RequestButton->setObjectName(QString::fromUtf8("RequestButton"));
        RequestButton->setGeometry(QRect(370, 0, 112, 32));
        ReplyButton = new QPushButton(centralwidget);
        ReplyButton->setObjectName(QString::fromUtf8("ReplyButton"));
        ReplyButton->setGeometry(QRect(20, 0, 112, 32));
        StarButton = new QPushButton(centralwidget);
        StarButton->setObjectName(QString::fromUtf8("StarButton"));
        StarButton->setGeometry(QRect(10, 520, 112, 32));
        StopButton = new QPushButton(centralwidget);
        StopButton->setObjectName(QString::fromUtf8("StopButton"));
        StopButton->setGeometry(QRect(130, 520, 112, 32));
        RepliesWidget = new QListWidget(centralwidget);
        RepliesWidget->setObjectName(QString::fromUtf8("RepliesWidget"));
        RepliesWidget->setGeometry(QRect(20, 30, 331, 461));
        RequestsWidget = new QListWidget(centralwidget);
        RequestsWidget->setObjectName(QString::fromUtf8("RequestsWidget"));
        RequestsWidget->setGeometry(QRect(370, 30, 371, 461));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 765, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        DumpButton->setText(QApplication::translate("MainWindow", "Dump", nullptr));
        SpiderButton->setText(QApplication::translate("MainWindow", "Spider", nullptr));
        RequestButton->setText(QApplication::translate("MainWindow", "Request", nullptr));
        ReplyButton->setText(QApplication::translate("MainWindow", "Reply", nullptr));
        StarButton->setText(QApplication::translate("MainWindow", "Start", nullptr));
        StopButton->setText(QApplication::translate("MainWindow", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
