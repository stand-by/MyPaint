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

//Director class is the manager of all drawing tools, view and scene;
class Director: public QObject {
    Q_OBJECT
private:
    //Director is the ownership of view, scene and tool
    //view
    View *view;
    //model
    QGraphicsScene *scene;
    //Director instance has only one drawing tool at certain time point
    AbstractDrawingTool *tool;
    //tunable color for any tool
    QColor toolColor;
public:
    explicit Director(QObject *parent = 0);
    ~Director();
    //set up passed color as tool color
    void setToolColor(const QColor &color);
    //next two methods change tool's pen width
    void increaseToolWidth();
    void decreaseToolWidth();
    //call appropriate scene's method
    void clearScene();
    //all another methods delete previous used tool, install appropriate drawing tool,
    //set color for this new tool and bind view and scene with this tool
    //(only one tool can be binded with view and scene at certain time point)
    void setCursorTool();
    void setPencilTool();
    void setLineTool();
    void setRectangleTool();
    void setFilledRectangleTool();
    void setEllipseTool();
    void setFilledEllipseTool();
    void setEraseTool();
    //returns current pixmap of view
    QPixmap getSceneImage() const;
    //set MainWindow as a friend of Director because of private members access necessity in MainWindow constructor
    friend class MainWindow;
};

#endif // DIRECTOR_H
