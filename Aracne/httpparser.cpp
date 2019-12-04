#include "httpparser.h"

HttpParser::HttpParser(){

}

void HttpParser::parseRequest(QByteArray request){
    char *msg = request.data();
    char *head = msg;
    char *mid;
    char *tail = head;

    if( request.size() == 0 ){
        return;
    }

    // Find request type
    while( *head++ != ' ');
    this->_http_request[ "Type" ] = std::string( ( char * ) msg ).substr( 0 , ( head - 1) - tail );

    // Find path
    tail = head;
    while( *head++ != ' ');
    this->_http_request[ "Path" ] = std::string( ( char * ) msg ).substr( tail - ( char *)msg , ( head - 1) - tail );

    // Find HTTP version
    tail = head;
    while( *head++ != '\r');
    this->_http_request[ "Version" ] = std::string( ( char * ) msg ).substr( tail - ( char *)msg , ( head - 1) - tail );

    // Map all headers from a key to a value
    while( true )
    {
        tail = head + 1;
        while( *head++ != '\r' );
        mid = strstr( tail, ":" );

        // Look for the failed strstr
        if( tail > mid )
            break;

        this->_http_request[ std::string( ( char * ) msg ).substr( tail - ( char *)msg , ( mid ) - tail  ) ] = std::string( ( char * ) msg ).substr( mid + 2 - ( char *) msg , ( head - 3 ) - mid );
    }
}

QString HttpParser::getHostname(){
    return QString(this->_http_request[ "Host" ].c_str());
}

QString HttpParser::getContentType(){
    return QString(this->_http_request[ "Content-Type" ].c_str());
}

QString HttpParser::getPath(){
    return QString(this->_http_request[ "Path" ].c_str());
}

QString HttpParser::getContentLength(){
    return QString(this->_http_request[ "Content-Length" ].c_str());
}

void HttpParser::setRequest(QByteArray request){
    this->_request = request;
}

QByteArray HttpParser::getRequest(){
    return this->_request;
}
