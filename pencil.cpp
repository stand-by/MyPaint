#include "pencil.h"

Pencil::Pencil(QObject *parent) : QObject(parent), pen(Qt::green) {
    canDraw = false;

    //color and size have to be customizeable
    pen.setWidth(2);
}
Pencil::~Pencil() {
    disconnect(view,SIGNAL(mousePress_transmitter(QMouseEvent*)),this,SLOT(mousePress_reciever(QMouseEvent *)));
    disconnect(view,SIGNAL(mouseMove_transmitter(QMouseEvent*)),this,SLOT(mouseMove_reciever(QMouseEvent *)));
    disconnect(view,SIGNAL(mouseRelease_transmitter(QMouseEvent*)),this,SLOT(mouseRelease_reciever(QMouseEvent *)));
    scene = NULL;
    view = NULL;
}

void Pencil::bindSceneAndView(QGraphicsScene *s, View *v) {
    scene = s;
    view = v;
    connect(view,SIGNAL(mousePress_transmitter(QMouseEvent*)),this,SLOT(mousePress_reciever(QMouseEvent *)));
    connect(view,SIGNAL(mouseMove_transmitter(QMouseEvent*)),this,SLOT(mouseMove_reciever(QMouseEvent *)));
    connect(view,SIGNAL(mouseRelease_transmitter(QMouseEvent*)),this,SLOT(mouseRelease_reciever(QMouseEvent *)));
}

void Pencil::mousePress_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        canDraw = true;
        scene->addLine(event->x(),event->y(),event->x(),event->y(),pen);
        oldPos = event->pos();
    }
}
void Pencil::mouseMove_reciever(QMouseEvent *event) {
    if (canDraw){
        newPos = event->pos();
        scene->addLine(QLine(oldPos, newPos), pen);
        oldPos = newPos;
     }
}
void Pencil::mouseRelease_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) canDraw = false;
}
