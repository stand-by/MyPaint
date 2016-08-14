#ifndef PENCILDRAWINGTOOL_H
#define PENCILDRAWINGTOOL_H

#include "AbstractDrawingTool/abstractdrawingtool.h"

class PencilDrawingTool: public AbstractDrawingTool {
protected:
    QPoint oldPos;
    QPoint newPos;
public:
    explicit PencilDrawingTool(QObject *parent = 0);
public slots:
    void mousePress_reciever(QMouseEvent *event);
    void mouseMove_reciever(QMouseEvent *event);
    void mouseRelease_reciever(QMouseEvent *event);
};

#endif // PENCILDRAWINGTOOL_H
