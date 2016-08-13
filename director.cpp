#include "director.h"

Director::Director() {
    scene = new QGraphicsScene(this);
    view = new View;
}

Director::~Director() {
    delete view;
    delete scene;
}

