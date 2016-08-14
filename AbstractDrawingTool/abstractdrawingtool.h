#ifndef ABSTRACTDRAWINGTOOL_H
#define ABSTRACTDRAWINGTOOL_H

#include <QObject>
#include <QPen>
#include <QPoint>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "View/view.h"

class AbstractDrawingTool : public QObject {
    Q_OBJECT
protected:
    bool canDraw;
    QPen pen;
    View *view;
    QGraphicsScene *scene;
public:
    explicit AbstractDrawingTool(QObject *parent = 0);
    ~AbstractDrawingTool();
    void bindSceneAndView(QGraphicsScene *s, View *v);
    void setPenColor(QColor color);
    void setPenWidth(int width);
    int getPenWidth();
public slots:
    virtual void mousePress_reciever(QMouseEvent *event) = 0;
    virtual void mouseMove_reciever(QMouseEvent *event) = 0;
    virtual void mouseRelease_reciever(QMouseEvent *event) = 0;
};

#endif // ABSTRACTDRAWINGTOOL_H
