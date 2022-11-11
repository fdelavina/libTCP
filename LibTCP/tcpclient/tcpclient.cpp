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

void TCPClient::sendData(QByteArray data_to_send)
{
    socket->connectToHost(m_url, m_port);

    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        qDebug() << "conectado!" ;
        if( socket->waitForConnected() )
        {
           socket->write( data_to_send );
           qDebug() << "sent " << data_to_send;
        }
    }
    else
    {
        qDebug() << "no ha sido posible la conexion" ;
    }
    socket->disconnect();
}
