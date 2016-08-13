#include "line.h"

Line::Line(QObject *parent) : QObject(parent), pen(Qt::blue) {
    canDraw = false;
    lastLine = NULL;

    //color and size have to be customizeable
    pen.setWidth(2);
}
Line::~Line() {
    disconnect(view,SIGNAL(mousePress_transmitter(QMouseEvent*)),this,SLOT(mousePress_reciever(QMouseEvent *)));
    disconnect(view,SIGNAL(mouseMove_transmitter(QMouseEvent*)),this,SLOT(mouseMove_reciever(QMouseEvent *)));
    disconnect(view,SIGNAL(mouseRelease_transmitter(QMouseEvent*)),this,SLOT(mouseRelease_reciever(QMouseEvent *)));
    scene = NULL;
    view = NULL;
    //do i need to delete this? check this line of code when tools are changing!!!
    delete lastLine;
}

void Line::bindSceneAndView(QGraphicsScene *s, View *v) {
    scene = s;
    view = v;
    connect(view,SIGNAL(mousePress_transmitter(QMouseEvent*)),this,SLOT(mousePress_reciever(QMouseEvent *)));
    connect(view,SIGNAL(mouseMove_transmitter(QMouseEvent*)),this,SLOT(mouseMove_reciever(QMouseEvent *)));
    connect(view,SIGNAL(mouseRelease_transmitter(QMouseEvent*)),this,SLOT(mouseRelease_reciever(QMouseEvent *)));
}

void Line::mousePress_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        canDraw = true;
        startPos = event->pos();
    }
}
void Line::mouseMove_reciever(QMouseEvent *event) {
    if (canDraw){
        lastPos = event->pos();
        if(lastLine != NULL) {
            scene->removeItem(lastLine);
            delete lastLine;
        }
        lastLine = scene->addLine(QLine(startPos, lastPos), pen);
     }
}
void Line::mouseRelease_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) canDraw = false;
    lastLine = NULL;
}
