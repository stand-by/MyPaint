#include "abstractdrawingtool.h"

AbstractDrawingTool::AbstractDrawingTool(QObject *parent) : QObject(parent) {
    scene = NULL;
    view = NULL;
    canDraw = false;
    //customize CapStyle, joinStyle here
    pen = QPen(Qt::black);
    pen.setWidth(1);
}
AbstractDrawingTool::~AbstractDrawingTool() {
    disconnect(view,SIGNAL(mousePress_transmitter(QMouseEvent*)),this,SLOT(mousePress_reciever(QMouseEvent *)));
    disconnect(view,SIGNAL(mouseMove_transmitter(QMouseEvent*)),this,SLOT(mouseMove_reciever(QMouseEvent *)));
    disconnect(view,SIGNAL(mouseRelease_transmitter(QMouseEvent*)),this,SLOT(mouseRelease_reciever(QMouseEvent *)));
    scene = NULL;
    view = NULL;
}

void AbstractDrawingTool::setPenColor(QColor color) {
    pen.setColor(color);
}
void AbstractDrawingTool::setPenWidth(int width) {
    pen.setWidth(width);
}

void AbstractDrawingTool::bindSceneAndView(QGraphicsScene *s, View *v) {
    scene = s;
    view = v;
    connect(view,SIGNAL(mousePress_transmitter(QMouseEvent*)),this,SLOT(mousePress_reciever(QMouseEvent *)));
    connect(view,SIGNAL(mouseMove_transmitter(QMouseEvent*)),this,SLOT(mouseMove_reciever(QMouseEvent *)));
    connect(view,SIGNAL(mouseRelease_transmitter(QMouseEvent*)),this,SLOT(mouseRelease_reciever(QMouseEvent *)));
}
