TEMPLATE = lib
QT += network
TARGET = TCPv0_0
CONFIG += dll
DEFINES += _TCP

include(Global/globalLib.pri)

include(tcpclient/tcpclient.pri)
include(tcpserver/tcpserver.pri)

