#include "linedrawingtool.h"

LineDrawingTool::LineDrawingTool(QObject *parent): AbstractDrawingTool(parent) {
    lastLine = NULL;
}

void LineDrawingTool::mousePress_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        canDraw = true;
        startPos = event->pos();
    }
}
void LineDrawingTool::mouseMove_reciever(QMouseEvent *event) {
    if (canDraw){
        lastPos = event->pos();
        if(lastLine != NULL) {
            scene->removeItem(lastLine);
            delete lastLine;
        }
        lastLine = scene->addLine(QLine(startPos, lastPos), pen);
     }
}
void LineDrawingTool::mouseRelease_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) canDraw = false;
    lastLine = NULL;
}
