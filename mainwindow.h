#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QColorDialog>
#include <QFileDialog>
#include "Director/director.h"

namespace Ui {
    class MainWindow;
}

//main class that serves whole application
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    //handlers for all actions from form
    //these actions allow user to choose instruments for drawing
    //all these handlers just call appropriate Director's tool setters and change icon of cursor
    void on_actionCursor_triggered();
    void on_actionPencil_triggered();
    void on_actionLine_triggered();
    void on_actionRectangle_triggered();
    void on_actionFilled_Rectangle_triggered();
    void on_actionEllipse_triggered();
    void on_actionFilled_Ellipse_triggered();
    void on_actionEraser_triggered();
    //this method allows user to choose custom color for any drawing tool
    void on_actionColor_Picker_triggered();
    //next two methods dedicated to change the width of tool
    void on_actionThinner_triggered();
    void on_actionThicker_triggered();
    //this method obtains pixmap of picture from director instance, then saves it in specified place
    void on_actionSave_As_triggered();
    //just clears current picture
    void on_actionNew_triggered();
private:
    Ui::MainWindow *ui;
    //director instance allows to manage drawing tools
    Director *director;
};

#endif // MAINWINDOW_H
