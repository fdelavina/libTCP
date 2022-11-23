#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include <qbytearray.h>
#include <QTcpSocket>

#include "Global/globalLib.h"

/*
 *
 * EXAMPLE OF USE
 *  m_tcp_client   = new TCPClient();
 *  QString url = "127.0.0.1";
 *  int port_tcp_server = 10000;
 *  m_port_udp_server = port_udp_server;
 *  m_url             = url;
 *  m_tcp_client->init(m_url, m_port_tcp_server);
 *
 *  m_tcp_client->sendData(QByteArray data_to_send) **** TODO ****
 *
 */
class TCPSHARED_EXPORT TCPClient : public QObject
{
    Q_OBJECT
public:
    TCPClient();
    ~TCPClient();
    void init(QString url, int port);

    void receiveData();
    void connectTCP();
    void disconnectTCP();
    void sendTCPMsg(QByteArray _data_to_send);

private:
    QTcpSocket *socket=nullptr;
    QByteArray data_to_be_sent;

    QString m_url;
    int m_port;
};

#endif // TCPCLIENT_H
