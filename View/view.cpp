#include "view.h"

View::View(QWidget *parent): QGraphicsView(parent) {
    this->setMouseTracking(true);
}

void View::mousePressEvent(QMouseEvent *event) {
    emit mousePress_transmitter(event);
}
void View::mouseMoveEvent(QMouseEvent *event) {
    emit mouseMove_transmitter(event);
}
void View::mouseReleaseEvent(QMouseEvent *event) {
    emit mouseRelease_transmitter(event);
}
