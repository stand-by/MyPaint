#ifndef RECTANGLEDRAWINGTOOL_H
#define RECTANGLEDRAWINGTOOL_H

#include "AbstractDrawingTool/abstractdrawingtool.h"

class RectangleDrawingTool : public AbstractDrawingTool {
protected:
    QPoint startPos;
    QPoint lastPos;
    QGraphicsItem *lastRectangle;
public:
    explicit RectangleDrawingTool(QObject *parent = 0);
public slots:
    void mousePress_reciever(QMouseEvent *event);
    void mouseMove_reciever(QMouseEvent *event);
    void mouseRelease_reciever(QMouseEvent *event);
};

#endif // RECTANGLEDRAWINGTOOL_H
