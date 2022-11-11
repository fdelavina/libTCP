TEMPLATE = app
TARGET = MiTestClient
QT -= gui
QT += network

CONFIG += c++11 console
SOURCES+=main.cpp
LIBS+= -L$$OUT_PWD//../LibTCP/Debug -llibTCPv0_0


INCLUDEPATH += $$PWD/../LibTCP
DEPENDPATH  += $$PWD/../LibTCP
