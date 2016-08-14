#ifndef ABSTRACTDRAWINGTOOL_H
#define ABSTRACTDRAWINGTOOL_H

#include <QObject>
#include <QPen>
#include <QPoint>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "View/view.h"

//abstract class that declares generic skeleton for tool
class AbstractDrawingTool: public QObject {
    Q_OBJECT
protected:
    bool canDraw;
    //pen for tool color, style and width customization
    QPen pen;
    //tool has no ownership of view and scene
    View *view;
    QGraphicsScene *scene;
public:
    explicit AbstractDrawingTool(QObject *parent = 0);
    //destructor disconnects slots from view signals
    ~AbstractDrawingTool();
    //method binds scene and view for creating and adding new shapes to scene using current drawing tool, connects slots to signals
    void bindSceneAndView(QGraphicsScene *s, View *v);
    void setPenColor(const QColor &color);
    void setPenWidth(const int &width);
    int getPenWidth() const;
public slots:
    //each tool class has to declare its own handlers for mouse events
    virtual void mousePress_reciever(QMouseEvent *event) = 0;
    virtual void mouseMove_reciever(QMouseEvent *event) = 0;
    virtual void mouseRelease_reciever(QMouseEvent *event) = 0;
};

#endif // ABSTRACTDRAWINGTOOL_H
