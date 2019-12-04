#include "aracne.h"
#include "proxy.h"
#include "client.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("Aracne");

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();
    QCommandLineOption portOption(QStringList() << "p" << "port",
                                  QCoreApplication::translate("main", "Porta proxy."),
                                  QCoreApplication::translate("main", "porta."));
    parser.addOption(portOption);

    parser.process(a);

    QString portValue = parser.value(portOption);

    Aracne w;
    w.show();

    Proxy *proxy = portValue.length() == 0 ? new Proxy(nullptr, &w) :
                                          new Proxy(nullptr, &w, static_cast<unsigned short>(std::stoul(portValue.toStdString())));
    proxy->start();

    return a.exec();
}
