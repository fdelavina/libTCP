#include "tcpserver.h"

TCPServer::TCPServer()
{
    m_server = new QTcpServer(this);
    connect(m_server,  &QTcpServer::newConnection, this, &TCPServer::onNewConnection);
}

TCPServer::~TCPServer()
{
    delete m_server;
}

void TCPServer::listen(QString _host, quint16 port)
{
    QHostAddress host(_host);

    if(!m_server->listen(QHostAddress::Any, port))
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
    m_socket = m_server->nextPendingConnection();
    m_socket->write("que paso");

}

void TCPServer::onReadyRead()
{
    qDebug() << "onReadyRead";
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    QByteArray datas = sender->readAll();
    qDebug() << "data:" << datas;
    qDebug() << "data:" << m_socket->readAll();
}

void TCPServer::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    qDebug() << "onSocketStateChanged " << socketState;
    if (socketState == QAbstractSocket::UnconnectedState)
    {
    }
}
