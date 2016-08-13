#include "rectangledrawingtool.h"

RectangleDrawingTool::RectangleDrawingTool(QObject *parent): AbstractDrawingTool(parent) {}

void RectangleDrawingTool::mousePress_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        canDraw = true;
        startPos = event->pos();
    }
}
void RectangleDrawingTool::mouseMove_reciever(QMouseEvent *event) {
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
void RectangleDrawingTool::mouseRelease_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) canDraw = false;
    lastRectangle = NULL;
}
