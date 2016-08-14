#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>

class View : public QGraphicsView {
    Q_OBJECT

public:
    explicit View(QWidget *parent = 0);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
signals:
    QMouseEvent* mousePress_transmitter(QMouseEvent *event);
    QMouseEvent* mouseMove_transmitter(QMouseEvent *event);
    QMouseEvent* mouseRelease_transmitter(QMouseEvent *event);
};

#endif // VIEW_H
