#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>

//custom class of QGraphicsView because of mouse events
class View: public QGraphicsView {
    Q_OBJECT
public:
    explicit View(QWidget *parent = 0);
protected:
    //methods for catching mouse events from view and then emitting signals for tool's slots
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
signals:
    QMouseEvent* mousePress_transmitter(QMouseEvent *event);
    QMouseEvent* mouseMove_transmitter(QMouseEvent *event);
    QMouseEvent* mouseRelease_transmitter(QMouseEvent *event);
};

#endif // VIEW_H
