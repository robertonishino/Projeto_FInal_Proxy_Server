#ifndef HTTPPARSER_H
#define HTTPPARSER_H

#include "QByteArray"
#include "QtDebug"
#include <iostream>
#include <map>
#include <string>

class HttpParser{

private:
    QByteArray _request;
    QByteArray _response;
    std::map<std::string, std::string> _http_request;

public:
    HttpParser();
    void parseResponse(QByteArray);
    void parseRequest(QByteArray);
    QString getHostname();
    QString getPath();
    QString getContentLength();
    QString getContentType();
    void setHostname(std::string);
    void setRequest(QByteArray);
    QByteArray getRequest();
};

#endif // HTTPPARSER_H
