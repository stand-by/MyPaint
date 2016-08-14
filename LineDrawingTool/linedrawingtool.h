#ifndef LINEDRAWINGTOOL_H
#define LINEDRAWINGTOOL_H

#include "AbstractDrawingTool/abstractdrawingtool.h"

//this class represents tool for line creating
class LineDrawingTool: public AbstractDrawingTool {
protected:
    QPoint startPos;
    QPoint lastPos;
    QGraphicsItem *lastLine;
public:
    explicit LineDrawingTool(QObject *parent = 0);
public slots:
    void mousePress_reciever(QMouseEvent *event);
    void mouseMove_reciever(QMouseEvent *event);
    void mouseRelease_reciever(QMouseEvent *event);
};

#endif // LINEDRAWINGTOOL_H
