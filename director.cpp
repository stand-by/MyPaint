#include "director.h"

Director::Director(QObject *parent): QObject(parent) {
    scene = new QGraphicsScene(this);
    view = new View;

    //synchronize scene's and view's coordinate systems
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    scene->setSceneRect(-1.25, -1.25, 2.5, 2.5);

    view->setScene(scene);
}

Director::~Director() {
    delete view;
    delete scene;
    delete pencil;
}

