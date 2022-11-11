#include "tcpserver.h"

TCPServer::TCPServer()
{
    server = new QTcpServer(this);
    connect(server,  &QTcpServer::newConnection, this, &TCPServer::onNewConnection);
}

TCPServer::~TCPServer()
{
    delete server;
}

void TCPServer::listen(QString _host, quint16 port)
{
    QHostAddress host(_host);

    if(!server->listen(QHostAddress::Any, port))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started in "<<host <<":"<< port;
    }
}

void TCPServer::onNewConnection()
{
    qDebug() << "new connection!! ";
    QTcpSocket *socket = server->nextPendingConnection();
    qDebug() << "new connection from: "<<socket->peerAddress()<<":"<<socket->peerPort();
    socket->waitForReadyRead();
    qDebug() << socket->bytesAvailable();
    const int MaxLength = 1024;
        char buffer[MaxLength + 1];

        qint64 byteCount = socket->read(buffer, MaxLength);
        buffer[byteCount] = 0;

        qDebug() << buffer;
    socket->close();
}
