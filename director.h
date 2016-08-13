#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <QObject>
#include <QGraphicsScene>
#include "view.h"
#include "pencil.h"
#include "line.h"
#include "rectangle.h"
#include "ellipse.h"

class Director: public QObject {
    Q_OBJECT

private:
    View *view;
    QGraphicsScene *scene;
    //instance for tool
    Pencil *pencil;
    Line *line;
    Rectangle *rectangle;
    Ellipse *ellipse;
public:
    explicit Director(QObject *parent = 0);
    ~Director();

    //set MainWindow as a friend of Director because of private members access necessity in MainWindow constructor
    friend class MainWindow;
};

#endif // DIRECTOR_H
