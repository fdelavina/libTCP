#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

#include "Global/globalLib.h"

class TCPSHARED_EXPORT TCPServer : public QObject
{
    Q_OBJECT
public:
    TCPServer();
    ~TCPServer();

    void listen( QString _host, quint16 port);

signals:

private slots:
    void onNewConnection();
    void onReadyRead();
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);

private:
    QTcpServer *m_server;
    QTcpSocket *m_socket;

};

#endif // TCPSERVER_H
