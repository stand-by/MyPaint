#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <QObject>
#include <QGraphicsScene>
#include "view.h"
#include "abstractdrawingtool.h"
#include "pencildrawingtool.h"
#include "linedrawingtool.h"
#include "rectangledrawingtool.h"
#include "ellipsedrawingtool.h"
#include "filledrectangledrawingtool.h"
#include "filledellipsedrawingtool.h"

class Director: public QObject {
    Q_OBJECT

private:
    View *view;
    QGraphicsScene *scene;
    //instance for tool
    AbstractDrawingTool *tool;
public:
    explicit Director(QObject *parent = 0);
    ~Director();

    //set MainWindow as a friend of Director because of private members access necessity in MainWindow constructor
    friend class MainWindow;
};

#endif // DIRECTOR_H
