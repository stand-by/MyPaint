#include "director.h"

Director::Director(QObject *parent): QObject(parent) {
    view = new View;
    scene = new QGraphicsScene(this);
    pencil = new Pencil(this);
    line = new Line(this);
    rectangle = new Rectangle(this);
    ellipse = new Ellipse(this);

    //synchronize scene's and view's coordinate systems
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    scene->setSceneRect(-1.25, -1.25, 2.5, 2.5);

    view->setScene(scene);

    ellipse->bindSceneAndView(scene, view);
    //rectangle->bindSceneAndView(scene, view);
    //line->bindSceneAndView(scene, view);
    //pencil->bindSceneAndView(scene, view);
    //???scene->addItem(pencil->getGraphicsItem());???
}

Director::~Director() {
    delete pencil;
    delete line;
    delete rectangle;
    delete ellipse;

    delete view;
    delete scene;
}

