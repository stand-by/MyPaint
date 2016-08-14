#include "director.h"

Director::Director(QObject *parent): QObject(parent) {
    tool = NULL;
    toolColor = Qt::black;
    view = new View;
    scene = new QGraphicsScene(this);

    //synchronize scene's and view's coordinate systems
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    scene->setSceneRect(-1.25, -1.25, 2.5, 2.5);
    //bind model and view
    view->setScene(scene);
}
Director::~Director() {
    delete tool;
    delete view;
    delete scene;
}

void Director::setToolColor(const QColor &color) {
    toolColor = color;
    if(tool != NULL) tool->setPenColor(toolColor);
}

void Director::increaseToolWidth() {
    if(tool != NULL) tool->setPenWidth(tool->getPenWidth()+1);
}
void Director::decreaseToolWidth() {
    if(tool != NULL && tool->getPenWidth() > 1) tool->setPenWidth(tool->getPenWidth()-1);
}

void Director::clearScene() {
    scene->clear();
}

void Director::setCursorTool() {
    if(tool != NULL) delete tool;
    tool = NULL;
}
void Director::setPencilTool() {
    if(tool != NULL) delete tool;
    tool = new PencilDrawingTool(this);
    tool->setPenColor(toolColor);
    tool->bindSceneAndView(scene, view);
}
void Director::setLineTool() {
    if(tool != NULL) delete tool;
    tool = new LineDrawingTool(this);
    tool->setPenColor(toolColor);
    tool->bindSceneAndView(scene, view);
}
void Director::setRectangleTool() {
    if(tool != NULL) delete tool;
    tool = new RectangleDrawingTool(this);
    tool->setPenColor(toolColor);
    tool->bindSceneAndView(scene, view);
}
void Director::setFilledRectangleTool() {
    if(tool != NULL) delete tool;
    tool = new FilledRectangleDrawingTool(this);
    tool->setPenColor(toolColor);
    tool->bindSceneAndView(scene, view);
}
void Director::setEllipseTool() {
    if(tool != NULL) delete tool;
    tool = new EllipseDrawingTool(this);
    tool->setPenColor(toolColor);
    tool->bindSceneAndView(scene, view);
}
void Director::setFilledEllipseTool() {
    if(tool != NULL) delete tool;
    tool = new FilledEllipseDrawingTool(this);
    tool->setPenColor(toolColor);
    tool->bindSceneAndView(scene, view);
}

void Director::setEraseTool() {
    if(tool != NULL) delete tool;
    tool = new EraserTool(this);
    tool->bindSceneAndView(scene, view);
}

QPixmap Director::getSceneImage() const {
    QPixmap pixMap = view->grab();
    return pixMap;
}
