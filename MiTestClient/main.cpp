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
    QByteArray bytes_to_send = "12";

    TCPClient* my_tcp_client = new TCPClient();

    my_tcp_client->init(url, port_tcp_server);
    my_tcp_client->sendData(bytes_to_send);

    delete my_tcp_client;

    return 0;
}
