#-------------------------------------------------
#
# Project created by QtCreator 2017-01-11T18:15:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Read_only_table
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    mymodel.cpp

HEADERS  += dialog.h \
    mymodel.h

FORMS    += dialog.ui
