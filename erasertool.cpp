#include "erasertool.h"

EraserTool::EraserTool(QObject *parent): AbstractDrawingTool(parent) {
    itemToErase = NULL;
}

void EraserTool::mousePress_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        canDraw = true;
        itemToErase = scene->itemAt(event->pos(), view->transform());
        if(itemToErase != 0) {
            scene->removeItem(itemToErase);
            delete itemToErase;
        }
    }
}
void EraserTool::mouseMove_reciever(QMouseEvent *event) {
    if (canDraw){
        itemToErase = scene->itemAt(event->pos(), view->transform());
        if(itemToErase != 0 ) {
            scene->removeItem(itemToErase);
            delete itemToErase;
        }
    }
}
void EraserTool::mouseRelease_reciever(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) canDraw = false;
    itemToErase = NULL;
}
