#include "ellipsedrawingtool.h"

EllipseDrawingTool::EllipseDrawingTool(QObject *parent): AbstractDrawingTool(parent) {}

void EllipseDrawingTool::mousePress_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        canDraw = true;
        startPos = event->pos();
    }
}
void EllipseDrawingTool::mouseMove_reciever(QMouseEvent *event) {
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
void EllipseDrawingTool::mouseRelease_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) canDraw = false;
    lastEllipse = NULL;
}

