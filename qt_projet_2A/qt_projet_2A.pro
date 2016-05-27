#-------------------------------------------------
#
# Project created by QtCreator 2016-05-24T16:07:09
#
#-------------------------------------------------

QT       += core gui opencv

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_projet_2A
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Ball.cpp \
    ssh.cpp

LIBS += `pkg-config opencv --libs` -lssh

HEADERS  += mainwindow.h \
    Ball.h \
    ssh.h

FORMS    += mainwindow.ui
