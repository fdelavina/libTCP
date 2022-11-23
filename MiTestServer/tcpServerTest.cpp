#include "tcpServerTest.h"

TCPServerTest::TCPServerTest(QObject *parent) : QObject(parent)
{
    my_tcp_server = new TCPServer();

    connect(my_tcp_server, SIGNAL(msgTCPAvailable(QByteArray)),this, SLOT(incomingTCPMessage(QByteArray)));

}

TCPServerTest::~TCPServerTest()
{
    delete my_tcp_server;
}

void TCPServerTest::serverListen(QString Url, int port)
{
    my_tcp_server->listen(Url, port);
}

void TCPServerTest::incomingTCPMessage(QByteArray _incommed_msg)
{
    qDebug()<< "Received message: " << _incommed_msg;
}
