#include "abstractdrawingtool.h"

AbstractDrawingTool::AbstractDrawingTool(QObject *parent) : QObject(parent) {
    canDraw = false;
    pen = QPen(Qt::black);
    pen.setWidth(1);
}
AbstractDrawingTool::~AbstractDrawingTool() {

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
