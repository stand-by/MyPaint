#ifndef PENCILDRAWINGTOOL_H
#define PENCILDRAWINGTOOL_H

#include "abstractdrawingtool.h"

class PencilDrawingTool: public AbstractDrawingTool {
    Q_OBJECT
protected:
    QPoint oldPos;
    QPoint newPos;
public slots:
    void mousePress_reciever(QMouseEvent *event);
    void mouseMove_reciever(QMouseEvent *event);
    void mouseRelease_reciever(QMouseEvent *event);
};

#endif // PENCILDRAWINGTOOL_H
