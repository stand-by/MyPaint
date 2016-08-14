#ifndef FILLEDRECTANGLEDRAWINGTOOL_H
#define FILLEDRECTANGLEDRAWINGTOOL_H

#include "rectangledrawingtool.h"

//this class represents tool for filled rectangle creating
class FilledRectangleDrawingTool: public RectangleDrawingTool {
public:
    explicit FilledRectangleDrawingTool(QObject *parent = 0);
    void mouseMove_reciever(QMouseEvent *event);
};

#endif // FILLEDRECTANGLEDRAWINGTOOL_H
