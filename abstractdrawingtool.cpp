#include "abstractdrawingtool.h"

AbstractDrawingTool::AbstractDrawingTool(QObject *parent) : QObject(parent) {
    canDraw = false;
    pen = QPen(Qt::black);
    pen.setWidth(1);
}
AbstractDrawingTool::~AbstractDrawingTool() {

}

