#include "filledrectangledrawingtool.h"

FilledRectangleDrawingTool::FilledRectangleDrawingTool(QObject *parent): RectangleDrawingTool(parent) {}

void FilledRectangleDrawingTool::mouseMove_reciever(QMouseEvent *event) {
    if (canDraw){
        lastPos = event->pos();
        if(lastRectangle != NULL) {
            scene->removeItem(lastRectangle);
            delete lastRectangle;
        }
        if(startPos.x()<=lastPos.x() && startPos.y()<=lastPos.y())
            lastRectangle = scene->addRect(QRect(startPos, lastPos), pen, QBrush(pen.color()));
        else if(startPos.x()>=lastPos.x() && startPos.y()>=lastPos.y())
            lastRectangle = scene->addRect(QRect(lastPos, startPos), pen, QBrush(pen.color()));
        else if(startPos.x()<=lastPos.x() && startPos.y()>=lastPos.y())
            lastRectangle = scene->addRect(QRect(QPoint(startPos.x(),lastPos.y()), QPoint(lastPos.x(),startPos.y())), pen, QBrush(pen.color()));
        else lastRectangle = scene->addRect(QRect(QPoint(lastPos.x(),startPos.y()), QPoint(startPos.x(),lastPos.y())), pen, QBrush(pen.color()));
    }
}
