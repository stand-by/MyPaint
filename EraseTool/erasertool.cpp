#include "erasertool.h"
#include <math.h>

EraserTool::EraserTool(QObject *parent): AbstractDrawingTool(parent) {
    canErase = false;
    itemToErase = NULL;
}

void EraserTool::mousePress_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        canErase = true;
        startPos = event->pos();
        itemToErase = scene->itemAt(startPos, view->transform());
        if(itemToErase != 0) {
            scene->removeItem(itemToErase);
            delete itemToErase;
        }
    }
}
void EraserTool::mouseMove_reciever(QMouseEvent *event) {
    if (canErase){
        lastPos = event->pos();
        itemToErase = scene->itemAt(lastPos, view->transform());
        if(itemToErase != 0 && sqrt(pow((startPos.x() - lastPos.x()),2) + pow((startPos.y() - lastPos.y()),2)) > 5) {
            scene->removeItem(itemToErase);
            delete itemToErase;
        }
    }
}
void EraserTool::mouseRelease_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) canErase = false;
    itemToErase = NULL;
}
