#include "director.h"

Director::Director(QObject *parent): QObject(parent) {
    view = new View;
    scene = new QGraphicsScene(this);
    tool = new FilledEllipseDrawingTool(this);

    //synchronize scene's and view's coordinate systems
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    scene->setSceneRect(-1.25, -1.25, 2.5, 2.5);

    view->setScene(scene);

    tool->bindSceneAndView(scene, view);
    //rectangle->bindSceneAndView(scene, view);
    //line->bindSceneAndView(scene, view);
    //pencil->bindSceneAndView(scene, view);
    //???scene->addItem(pencil->getGraphicsItem());???
}
Director::~Director() {
    delete tool;

    delete view;
    delete scene;
}

void Director::setCursorTool() {

}
void Director::setPencilTool() {

}
void Director::setLineTool() {

}
void Director::setRectangleTool() {

}
void Director::setFilledRectangleTool() {

}
void Director::setEllipseTool() {

}
void Director::setFilledEllipseTool() {

}

