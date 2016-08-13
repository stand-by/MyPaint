#ifndef PENCIL_H
#define PENCIL_H

#include <QObject>
#include <QPen>
#include <QPoint>
#include <QMouseEvent>
#include <QGraphicsScene>
#include "view.h"

class Pencil : public QObject
{
    Q_OBJECT
public:
    explicit Pencil(QObject *parent = 0);
    ~Pencil();
    void bindSceneAndView(QGraphicsScene *s, View *v);
private:
    bool canDraw;
    QPen pen;
    QPoint oldPos;
    QPoint newPos;
    QGraphicsScene *scene;
    View *view;
public slots:
    void mousePress_reciever(QMouseEvent *event);
    void mouseMove_reciever(QMouseEvent *event);
    void mouseRelease_reciever(QMouseEvent *event);
};

#endif // PENCIL_H
