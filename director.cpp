#include "director.h"

Director::Director(QObject *parent): QObject(parent) {
    tool = NULL;
    view = new View;
    scene = new QGraphicsScene(this);

    //synchronize scene's and view's coordinate systems
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    scene->setSceneRect(-1.25, -1.25, 2.5, 2.5);

    view->setScene(scene);
    this->setPencilTool();

    //tool->bindSceneAndView(scene, view);
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

}
void Director::setFilledRectangleTool() {

}
void Director::setEllipseTool() {

}
void Director::setFilledEllipseTool() {

}

