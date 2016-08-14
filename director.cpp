#include "director.h"

Director::Director(QObject *parent): QObject(parent) {
    tool = NULL;
    toolColor = Qt::black;
    view = new View;
    scene = new QGraphicsScene(this);

    //synchronize scene's and view's coordinate systems
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    scene->setSceneRect(-1.25, -1.25, 2.5, 2.5);

    view->setScene(scene);
}
Director::~Director() {
    delete tool;

    delete view;
    delete scene;
}

void Director::setCursorTool() {
    if(tool != NULL) delete tool;
    tool = NULL;
}
void Director::setPencilTool() {
    if(tool != NULL) delete tool;
    tool = new PencilDrawingTool(this);
    tool->bindSceneAndView(scene, view);
}
void Director::setLineTool() {
    if(tool != NULL) delete tool;
    tool = new LineDrawingTool(this);
    tool->bindSceneAndView(scene, view);
}
void Director::setRectangleTool() {
    if(tool != NULL) delete tool;
    tool = new RectangleDrawingTool(this);
    tool->bindSceneAndView(scene, view);
}
void Director::setFilledRectangleTool() {
    if(tool != NULL) delete tool;
    tool = new FilledRectangleDrawingTool(this);
    tool->bindSceneAndView(scene, view);
}
void Director::setEllipseTool() {
    if(tool != NULL) delete tool;
    tool = new EllipseDrawingTool(this);
    tool->bindSceneAndView(scene, view);
}
void Director::setFilledEllipseTool() {
    if(tool != NULL) delete tool;
    tool = new FilledEllipseDrawingTool(this);
    tool->bindSceneAndView(scene, view);
}

void Director::setEraseTool() {
    if(tool != NULL) delete tool;
    tool = new EraserTool(this);
    tool->bindSceneAndView(scene, view);
}
