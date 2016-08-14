#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QColorDialog>
#include <QFileDialog>
#include "director.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_actionCursor_triggered();
    void on_actionPencil_triggered();
    void on_actionLine_triggered();
    void on_actionRectangle_triggered();
    void on_actionFilled_Rectangle_triggered();
    void on_actionEllipse_triggered();
    void on_actionFilled_Ellipse_triggered();
    void on_actionColor_Picker_triggered();
    void on_actionEraser_triggered();
    void on_actionThinner_triggered();
    void on_actionThicker_triggered();
    void on_actionSave_As_triggered();
private:
    Ui::MainWindow *ui;
    Director *director;
};

#endif // MAINWINDOW_H
