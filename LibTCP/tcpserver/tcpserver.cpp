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
    m_socket = m_server->nextPendingConnection();
    if (m_socket->waitForConnected())
    {
        qDebug() << "new connection!! ";
    }
    if(m_socket->state() == QAbstractSocket::ConnectedState)
    {
        qDebug() << "estado: " <<m_socket->state();
        if (m_socket->waitForReadyRead() )
        {
            m_incoming_msg = m_socket->readAll();
            qDebug() << "read data " << m_incoming_msg;

            emit msgTCPAvailable(m_incoming_msg);

        }
    }
}



void TCPServer::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    qDebug() << "onSocketStateChanged " << socketState;
    if (socketState == QAbstractSocket::UnconnectedState)
    {
    }
}
