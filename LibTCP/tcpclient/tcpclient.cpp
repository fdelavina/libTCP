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

void TCPClient::setDataToBeSent(QByteArray _)
{
    data_to_be_sent = _;
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

void TCPClient::sendData()
{
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        qDebug() << "send data " << socket->write("escribo desde cliente");

        socket->waitForBytesWritten();
    }
}
