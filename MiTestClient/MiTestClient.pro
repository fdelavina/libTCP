TEMPLATE = app
TARGET = MiTestClient
QT -= gui
QT += network

CONFIG += c++11 console
SOURCES+=main.cpp
LIBS+= -L$$OUT_PWD//../LibTCP/Debug -lTCPv0_0

message($$OUT_PWD)
INCLUDEPATH += $$PWD/../LibTCP
DEPENDPATH  += $$PWD/../LibTCP
