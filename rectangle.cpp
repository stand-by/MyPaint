#include "rectangle.h"

Rectangle::Rectangle(QObject *parent) : QObject(parent), pen(Qt::red) {
    canDraw = false;
    lastRectangle = NULL;

    //color and size have to be customizeable
    pen.setWidth(2);
}
Rectangle::~Rectangle() {
    disconnect(view,SIGNAL(mousePress_transmitter(QMouseEvent*)),this,SLOT(mousePress_reciever(QMouseEvent *)));
    disconnect(view,SIGNAL(mouseMove_transmitter(QMouseEvent*)),this,SLOT(mouseMove_reciever(QMouseEvent *)));
    disconnect(view,SIGNAL(mouseRelease_transmitter(QMouseEvent*)),this,SLOT(mouseRelease_reciever(QMouseEvent *)));
    scene = NULL;
    view = NULL;
    //do i need to delete this? check this line of code when tools are changing!!!
    delete lastRectangle;
}

void Rectangle::bindSceneAndView(QGraphicsScene *s, View *v) {
    scene = s;
    view = v;
    connect(view,SIGNAL(mousePress_transmitter(QMouseEvent*)),this,SLOT(mousePress_reciever(QMouseEvent *)));
    connect(view,SIGNAL(mouseMove_transmitter(QMouseEvent*)),this,SLOT(mouseMove_reciever(QMouseEvent *)));
    connect(view,SIGNAL(mouseRelease_transmitter(QMouseEvent*)),this,SLOT(mouseRelease_reciever(QMouseEvent *)));
}

void Rectangle::mousePress_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        canDraw = true;
        startPos = event->pos();
    }
}
void Rectangle::mouseMove_reciever(QMouseEvent *event) {
    if (canDraw){
        lastPos = event->pos();
        if(lastRectangle != NULL) {
            scene->removeItem(lastRectangle);
            delete lastRectangle;
        }
        if(startPos.x()<=lastPos.x() && startPos.y()<=lastPos.y())
            lastRectangle = scene->addRect(QRect(startPos, lastPos), pen /*add brush here for filled rect*/);
        else if(startPos.x()>=lastPos.x() && startPos.y()>=lastPos.y())
            lastRectangle = scene->addRect(QRect(lastPos, startPos), pen /*add brush here for filled rect*/);
        else if(startPos.x()<=lastPos.x() && startPos.y()>=lastPos.y())
            lastRectangle = scene->addRect(QRect(QPoint(startPos.x(),lastPos.y()), QPoint(lastPos.x(),startPos.y())), pen /*add brush here for filled rect*/);
        else lastRectangle = scene->addRect(QRect(QPoint(lastPos.x(),startPos.y()), QPoint(startPos.x(),lastPos.y())), pen /*add brush here for filled rect*/);
    }
}
void Rectangle::mouseRelease_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) canDraw = false;
    lastRectangle = NULL;
}
