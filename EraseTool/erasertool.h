#ifndef ERASERTOOL_H
#define ERASERTOOL_H

#include "AbstractDrawingTool/abstractdrawingtool.h"

class EraserTool: public AbstractDrawingTool {
protected:
    bool canErase;
    QPoint startPos;
    QPoint lastPos;
    QGraphicsItem *itemToErase;
public:
    explicit EraserTool(QObject *parent = 0);
public slots:
    void mousePress_reciever(QMouseEvent *event);
    void mouseMove_reciever(QMouseEvent *event);
    void mouseRelease_reciever(QMouseEvent *event);
};

#endif // ERASERTOOL_H
