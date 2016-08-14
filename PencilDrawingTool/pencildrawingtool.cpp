#include "pencildrawingtool.h"

PencilDrawingTool::PencilDrawingTool(QObject *parent): AbstractDrawingTool(parent) {
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
}

void PencilDrawingTool::mousePress_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        canDraw = true;
        scene->addLine(event->x(),event->y(),event->x(),event->y(),pen);
        oldPos = event->pos();
    }
}
void PencilDrawingTool::mouseMove_reciever(QMouseEvent *event) {
    if (canDraw){
        newPos = event->pos();
        scene->addLine(QLine(oldPos, newPos), pen);
        oldPos = newPos;
     }
}
void PencilDrawingTool::mouseRelease_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) canDraw = false;
}
