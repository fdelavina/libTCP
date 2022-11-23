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
    void msgTCPAvailable(QByteArray _data_received);

private slots:
    void onNewConnection();
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);

private:
    QTcpServer *m_server;
    QTcpSocket *m_socket;

    QByteArray m_incoming_msg;

};

#endif // TCPSERVER_H
