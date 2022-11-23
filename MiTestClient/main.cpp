#include <QDebug>
#include <QByteArray>
#include "tcpclient/tcpclient.h"

using namespace std;


int main(int argc, char** argv)
{
    if (argc !=3)
    {
        qDebug() << "arguments must be URL and port.";
        qDebug() << "Example >>> name.exe 127.0.0.1 3000";
    }
    QString url_arg;
    QString port_arg;
    for (int i = 0; i < argc; ++i)
    {
        if(i ==1) url_arg  = argv[i] ;
        if(i ==2) port_arg = argv[i] ;
    }

    QString url = url_arg;
    int port_tcp_server = port_arg.toInt();


    TCPClient* my_tcp_client = new TCPClient();
    my_tcp_client->init(url, port_tcp_server);
    my_tcp_client->connectTCP();

    QByteArray array_to_be_sent;
    array_to_be_sent.resize(2);
    array_to_be_sent[0] = 0xFF;
    array_to_be_sent[1] = 0x0F;
    my_tcp_client->sendTCPMsg(array_to_be_sent);
    my_tcp_client->disconnectTCP();

    delete my_tcp_client;

    return 0;
}
