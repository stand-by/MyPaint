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
    AbstractDrawingTool/abstractdrawingtool.cpp \
    Director/director.cpp \
    EllipseDrawingTools/ellipsedrawingtool.cpp \
    EllipseDrawingTools/filledellipsedrawingtool.cpp \
    EraseTool/erasertool.cpp \
    LineDrawingTool/linedrawingtool.cpp \
    PencilDrawingTool/pencildrawingtool.cpp \
    RectangleDrawingTools/filledrectangledrawingtool.cpp \
    RectangleDrawingTools/rectangledrawingtool.cpp \
    View/view.cpp

HEADERS  += mainwindow.h \
    AbstractDrawingTool/abstractdrawingtool.h \
    Director/director.h \
    EllipseDrawingTools/ellipsedrawingtool.h \
    EllipseDrawingTools/filledellipsedrawingtool.h \
    EraseTool/erasertool.h \
    LineDrawingTool/linedrawingtool.h \
    PencilDrawingTool/pencildrawingtool.h \
    RectangleDrawingTools/filledrectangledrawingtool.h \
    RectangleDrawingTools/rectangledrawingtool.h \
    View/view.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons/icons.qrc
