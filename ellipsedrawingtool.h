#ifndef ELLIPSEDRAWINGTOOL_H
#define ELLIPSEDRAWINGTOOL_H

#include "abstractdrawingtool.h"

class EllipseDrawingTool : public AbstractDrawingTool {
protected:
    QPoint startPos;
    QPoint lastPos;
    QGraphicsItem *lastEllipse;
public:
    explicit EllipseDrawingTool(QObject *parent = 0);
public slots:
    void mousePress_reciever(QMouseEvent *event);
    void mouseMove_reciever(QMouseEvent *event);
    void mouseRelease_reciever(QMouseEvent *event);
};

#endif // ELLIPSEDRAWINGTOOL_H
