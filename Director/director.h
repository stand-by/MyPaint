#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <QObject>
#include <QImage>
#include <QGraphicsScene>
#include "View/view.h"
#include "AbstractDrawingTool/abstractdrawingtool.h"
#include "PencilDrawingTool/pencildrawingtool.h"
#include "LineDrawingTool/linedrawingtool.h"
#include "RectangleDrawingTools/rectangledrawingtool.h"
#include "EllipseDrawingTools/ellipsedrawingtool.h"
#include "RectangleDrawingTools/filledrectangledrawingtool.h"
#include "EllipseDrawingTools/filledellipsedrawingtool.h"
#include "EraseTool/erasertool.h"

class Director: public QObject {
    Q_OBJECT
private:
    View *view;
    QGraphicsScene *scene;
    AbstractDrawingTool *tool;
    QColor toolColor;
public:
    explicit Director(QObject *parent = 0);
    ~Director();
    void setToolColor(const QColor &color);
    void increaseToolWidth();
    void decreaseToolWidth();
    void clearScene();
    void setCursorTool();
    void setPencilTool();
    void setLineTool();
    void setRectangleTool();
    void setFilledRectangleTool();
    void setEllipseTool();
    void setFilledEllipseTool();
    void setEraseTool();
    QPixmap getSceneImage() const;
    //set MainWindow as a friend of Director because of private members access necessity in MainWindow constructor
    friend class MainWindow;
};

#endif // DIRECTOR_H
