#include "tcpclient.h"
#include <QDebug>

TCPClient::TCPClient()
{
}

TCPClient::~TCPClient()
{
    delete [] socket;
}

void TCPClient::init(QString url, int port)
{
    m_url = url;
    m_port = port;

    socket = new QTcpSocket( this );
    qDebug() << "socket will be connect to url" << m_url <<
                "and port " << m_port;
}

void TCPClient::receiveData()
{
    qDebug() << "waiting for be connected" ;
    if( socket->waitForConnected() )
    {
        if(socket->state() == QAbstractSocket::ConnectedState)
        {
            qDebug() << "conectado!" ;
            if (socket->waitForReadyRead() )
            {
                qDebug() << "read data " << socket->readAll();
                socket->readAll();
            }
        }
    }
    else
    {
        qDebug() << "no ha sido posible la conexion" ;
    }

}

void TCPClient::connectTCP()
{
    socket->connectToHost(m_url, m_port);
    if (socket->waitForConnected() )
    {
        qDebug() << "connected!";
    }

}

void TCPClient::disconnectTCP()
{
    socket->disconnect();
    qDebug() << "disconnect!";
}

void TCPClient::sendTCPMsg(QByteArray _data_to_send)
{
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->write(_data_to_send);
        qDebug() << "sending data " << _data_to_send;

        socket->waitForBytesWritten();
    }
    else
    {
        qDebug() << "data has not been sent because no connection stablished";
    }
}
