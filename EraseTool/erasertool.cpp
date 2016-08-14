#include "erasertool.h"
#include <math.h>

EraserTool::EraserTool(QObject *parent): AbstractDrawingTool(parent) {
    itemToErase = NULL;
}

void EraserTool::mousePress_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        canDraw = true;
        startPos = event->pos();
        itemToErase = scene->itemAt(event->pos(), view->transform());
        if(itemToErase != 0) {
            scene->removeItem(itemToErase);
            delete itemToErase;
        }
    }
}
void EraserTool::mouseMove_reciever(QMouseEvent *event) {
    if (canDraw){
        lastPos = event->pos();
        itemToErase = scene->itemAt(event->pos(), view->transform());
        if(itemToErase != 0 && sqrt(pow((startPos.x() - lastPos.x()),2) + pow((startPos.y() - lastPos.y()),2)) > 5) {
            scene->removeItem(itemToErase);
            delete itemToErase;
        }
    }
}
void EraserTool::mouseRelease_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) canDraw = false;
    itemToErase = NULL;
}
