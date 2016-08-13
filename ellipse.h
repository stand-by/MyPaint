#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QObject>
#include <QPen>
#include <QPoint>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "view.h"

class Ellipse : public QObject {
    Q_OBJECT
public:
    explicit Ellipse(QObject *parent = 0);
    ~Ellipse();
    void bindSceneAndView(QGraphicsScene *s, View *v);
private:
    bool canDraw;
    QPen pen;
    QPoint startPos;
    QPoint lastPos;
    QGraphicsScene *scene;
    QGraphicsItem *lastEllipse;
    View *view;
public slots:
    void mousePress_reciever(QMouseEvent *event);
    void mouseMove_reciever(QMouseEvent *event);
    void mouseRelease_reciever(QMouseEvent *event);
};
#endif // ELLIPSE_H
