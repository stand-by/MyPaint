#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <QObject>
#include <QGraphicsScene>
#include "view.h"
#include "pencil.h"

class Director: public QObject {
    Q_OBJECT

private:
    View *view;
    QGraphicsScene *scene;
    //instance for tool
    Pencil *pencil;
public:
    explicit Director(QObject *parent = 0);
    ~Director();
};

#endif // DIRECTOR_H
