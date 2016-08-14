#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <QObject>
#include <QGraphicsScene>
#include "view.h"
#include "abstractdrawingtool.h"
#include "pencildrawingtool.h"
#include "linedrawingtool.h"
#include "rectangledrawingtool.h"
#include "ellipsedrawingtool.h"
#include "filledrectangledrawingtool.h"
#include "filledellipsedrawingtool.h"
#include "erasertool.h"

class Director: public QObject {
    Q_OBJECT

private:
    View *view;
    QGraphicsScene *scene;
    //instance for tool
    AbstractDrawingTool *tool;
    QColor toolColor;
public:
    explicit Director(QObject *parent = 0);
    ~Director();
    void setToolColor(QColor color);
    void increaseToolWidth();
    void decreaseToolWidth();
    void setCursorTool();
    void setPencilTool();
    void setLineTool();
    void setRectangleTool();
    void setFilledRectangleTool();
    void setEllipseTool();
    void setFilledEllipseTool();
    void setEraseTool();
    //set MainWindow as a friend of Director because of private members access necessity in MainWindow constructor
    friend class MainWindow;
};

#endif // DIRECTOR_H
