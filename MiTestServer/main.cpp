
#include "tcpserver/tcpserver.h"
#include "tcpServerTest.h"
#include <QCoreApplication>
#include <QByteArray>
using namespace std;


int main(int argc, char** argv)
{
    QCoreApplication a(argc, argv);
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

    TCPServerTest my_server_test;
    my_server_test.serverListen(url, port_tcp_server);




    return a.exec();
}
