#ifndef LINE_H
#define LINE_H

#include <QObject>
#include <QPen>
#include <QPoint>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "view.h"

class Line : public QObject {
    Q_OBJECT
public:
    explicit Line(QObject *parent = 0);
    ~Line();
    void bindSceneAndView(QGraphicsScene *s, View *v);
private:
    bool canDraw;
    QPen pen;
    QPoint startPos;
    QPoint lastPos;
    QGraphicsScene *scene;
    QGraphicsItem *lastLine;
    View *view;
public slots:
    void mousePress_reciever(QMouseEvent *event);
    void mouseMove_reciever(QMouseEvent *event);
    void mouseRelease_reciever(QMouseEvent *event);
};

#endif // LINE_H
