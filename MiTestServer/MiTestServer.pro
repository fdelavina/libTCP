TEMPLATE = app
TARGET = MiTestServer
QT -= gui
QT += network
CONFIG += c++11 console
SOURCES+=main.cpp
LIBS+= -L$$OUT_PWD//../LibTCP/Debug -lTCPv0_0


INCLUDEPATH += $$PWD/../LibTCP
DEPENDPATH  += $$PWD/../LibTCP
