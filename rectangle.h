#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QObject>
#include <QPen>
#include <QPoint>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "view.h"

class Rectangle : public QObject {
    Q_OBJECT
public:
    explicit Rectangle(QObject *parent = 0);
    ~Rectangle();
    void bindSceneAndView(QGraphicsScene *s, View *v);
private:
    bool canDraw;
    QPen pen;
    QPoint startPos;
    QPoint lastPos;
    QGraphicsScene *scene;
    QGraphicsItem *lastRectangle;
    View *view;
public slots:
    void mousePress_reciever(QMouseEvent *event);
    void mouseMove_reciever(QMouseEvent *event);
    void mouseRelease_reciever(QMouseEvent *event);
};

#endif // RECTANGLE_H
