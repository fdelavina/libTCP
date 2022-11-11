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

private:
    QTcpServer *server;

};

#endif // TCPSERVER_H
