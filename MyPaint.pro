#-------------------------------------------------
#
# Project created by QtCreator 2016-08-13T10:16:36
#
#-------------------------------------------------


QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyPaint
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    view.cpp \
    director.cpp \
    pencil.cpp \
    line.cpp \
    rectangle.cpp \
    ellipse.cpp \
    abstractdrawingtool.cpp

HEADERS  += mainwindow.h \
    view.h \
    director.h \
    pencil.h \
    line.h \
    rectangle.h \
    ellipse.h \
    abstractdrawingtool.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons/icons.qrc
