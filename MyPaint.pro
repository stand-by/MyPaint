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
    abstractdrawingtool.cpp \
    pencildrawingtool.cpp \
    linedrawingtool.cpp \
    rectangledrawingtool.cpp \
    ellipsedrawingtool.cpp

HEADERS  += mainwindow.h \
    view.h \
    director.h \
    abstractdrawingtool.h \
    pencildrawingtool.h \
    linedrawingtool.h \
    rectangledrawingtool.h \
    ellipsedrawingtool.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons/icons.qrc
