#ifndef TCPSERVERTEST_H
#define TCPSERVERTEST_H

#include <QObject>

#include "tcpserver/tcpserver.h"

class TCPServerTest : public QObject
{
    Q_OBJECT
public:
    explicit TCPServerTest(QObject *parent = nullptr);
    ~TCPServerTest();
    void serverListen(QString Url, int port);
signals:

private slots:
    void incomingTCPMessage(QByteArray _incommed_msg);
private:
    TCPServer* my_tcp_server ;

};

#endif // TCPSERVERTEST_H
