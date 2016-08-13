#include "abstractdrawingtool.h"

AbstractDrawingTool::AbstractDrawingTool(QObject *parent) : QObject(parent) {
    canDraw = false;
    pen = QPen(Qt::black);
    pen.setWidth(1);
}
AbstractDrawingTool::~AbstractDrawingTool() {

}

void AbstractDrawingTool::setPenColor(QColor color) {
    pen.setColor(color);
}
void AbstractDrawingTool::setPenWidth(int width) {
    pen.setWidth(width);
}
