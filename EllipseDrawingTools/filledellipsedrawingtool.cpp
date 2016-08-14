#include "filledellipsedrawingtool.h"

FilledEllipseDrawingTool::FilledEllipseDrawingTool(QObject *parent): EllipseDrawingTool(parent) {}

void FilledEllipseDrawingTool::mouseMove_reciever(QMouseEvent *event) {
    if (canDraw){
        lastPos = event->pos();
        if(lastEllipse != NULL) {
            scene->removeItem(lastEllipse);
            delete lastEllipse;
        }
        if(startPos.x()<=lastPos.x() && startPos.y()<=lastPos.y())
            lastEllipse = scene->addEllipse(QRect(startPos, lastPos), pen, QBrush(pen.color()));
        else if(startPos.x()>=lastPos.x() && startPos.y()>=lastPos.y())
            lastEllipse = scene->addEllipse(QRect(lastPos, startPos), pen, QBrush(pen.color()));
        else if(startPos.x()<=lastPos.x() && startPos.y()>=lastPos.y())
            lastEllipse = scene->addEllipse(QRect(QPoint(startPos.x(),lastPos.y()), QPoint(lastPos.x(),startPos.y())), pen, QBrush(pen.color()));
        else lastEllipse = scene->addEllipse(QRect(QPoint(lastPos.x(),startPos.y()), QPoint(startPos.x(),lastPos.y())), pen, QBrush(pen.color()));
    }
}
