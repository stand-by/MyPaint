#include "director.h"

Director::Director(QObject *parent): QObject(parent) {
    scene = new QGraphicsScene(this);
    view = new View;
}

Director::~Director() {
    delete view;
    delete scene;
}

