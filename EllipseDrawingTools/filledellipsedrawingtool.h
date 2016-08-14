#ifndef FILLEDELLIPSEDRAWINGTOOL_H
#define FILLEDELLIPSEDRAWINGTOOL_H

#include "ellipsedrawingtool.h"

//this class represents tool for filled ellipse creating
class FilledEllipseDrawingTool: public EllipseDrawingTool {
public:
    explicit FilledEllipseDrawingTool(QObject *parent = 0);
    void mouseMove_reciever(QMouseEvent *event);
};

#endif // FILLEDELLIPSEDRAWINGTOOL_H
