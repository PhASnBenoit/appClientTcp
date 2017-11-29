#-------------------------------------------------
#
# Project created by QtCreator 2017-10-02T02:11:26
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = appClientTcp
TEMPLATE = app


SOURCES += main.cpp\
        cihmappclienttcp.cpp \
    cclienttcp.cpp

HEADERS  += cihmappclienttcp.h \
    cclienttcp.h

FORMS    += cihmappclienttcp.ui
