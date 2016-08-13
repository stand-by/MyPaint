#include "ellipse.h"

Ellipse::Ellipse(QObject *parent) : QObject(parent), pen(Qt::yellow) {
    canDraw = false;
    lastEllipse = NULL;

    //color and size have to be customizeable
    pen.setWidth(2);
}
Ellipse::~Ellipse() {
    disconnect(view,SIGNAL(mousePress_transmitter(QMouseEvent*)),this,SLOT(mousePress_reciever(QMouseEvent *)));
    disconnect(view,SIGNAL(mouseMove_transmitter(QMouseEvent*)),this,SLOT(mouseMove_reciever(QMouseEvent *)));
    disconnect(view,SIGNAL(mouseRelease_transmitter(QMouseEvent*)),this,SLOT(mouseRelease_reciever(QMouseEvent *)));
    scene = NULL;
    view = NULL;
    //do i need to delete this? check this line of code when tools are changing!!!
    delete lastEllipse;
}

void Ellipse::bindSceneAndView(QGraphicsScene *s, View *v) {
    scene = s;
    view = v;
    connect(view,SIGNAL(mousePress_transmitter(QMouseEvent*)),this,SLOT(mousePress_reciever(QMouseEvent *)));
    connect(view,SIGNAL(mouseMove_transmitter(QMouseEvent*)),this,SLOT(mouseMove_reciever(QMouseEvent *)));
    connect(view,SIGNAL(mouseRelease_transmitter(QMouseEvent*)),this,SLOT(mouseRelease_reciever(QMouseEvent *)));
}

void Ellipse::mousePress_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        canDraw = true;
        startPos = event->pos();
    }
}
void Ellipse::mouseMove_reciever(QMouseEvent *event) {
    if (canDraw){
        lastPos = event->pos();
        if(lastEllipse != NULL) {
            scene->removeItem(lastEllipse);
            delete lastEllipse;
        }
        if(startPos.x()<=lastPos.x() && startPos.y()<=lastPos.y())
            lastEllipse = scene->addEllipse(QRect(startPos, lastPos), pen /*add brush here for filled rect*/);
        else if(startPos.x()>=lastPos.x() && startPos.y()>=lastPos.y())
            lastEllipse = scene->addEllipse(QRect(lastPos, startPos), pen /*add brush here for filled rect*/);
        else if(startPos.x()<=lastPos.x() && startPos.y()>=lastPos.y())
            lastEllipse = scene->addEllipse(QRect(QPoint(startPos.x(),lastPos.y()), QPoint(lastPos.x(),startPos.y())), pen /*add brush here for filled rect*/);
        else lastEllipse = scene->addEllipse(QRect(QPoint(lastPos.x(),startPos.y()), QPoint(startPos.x(),lastPos.y())), pen /*add brush here for filled rect*/);
    }
}
void Ellipse::mouseRelease_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) canDraw = false;
    lastEllipse = NULL;
}

