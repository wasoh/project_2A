#-------------------------------------------------
#
# Project created by QtCreator 2016-05-24T16:07:09
#
#-------------------------------------------------

QT       += core gui opengl
QT_CONFIG -= no-pkg-config
CONFIG += link_pkgconfig
PKGCONFIG += opencv

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_projet_2A
TEMPLATE = app

INCLUDEPATH     +=

LIBS  += 'pkg-config opencv --libs'

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -Wall
