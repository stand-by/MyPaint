#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <QObject>
#include <QGraphicsScene>
#include "view.h"

class Director: public QObject {
    Q_OBJECT

private:
    View *view;
    QGraphicsScene *scene;
public:
    Director();
    ~Director();
};

#endif // DIRECTOR_H
