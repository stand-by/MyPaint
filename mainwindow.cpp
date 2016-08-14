#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    director = new Director(this);

    this->setWindowTitle("MyPaint");
    this->setCentralWidget(director->view);

    //this->setCursor(QCursor(QPixmap(":/icons/Ellipse\ Stroked-48.png")));
}

MainWindow::~MainWindow() {
    delete director;
    delete ui;
}

void MainWindow::on_actionCursor_triggered() {

}
void MainWindow::on_actionPencil_triggered() {

}
void MainWindow::on_actionLine_triggered() {

}
void MainWindow::on_actionRectangle_triggered() {

}
void MainWindow::on_actionFilled_Rectangle_triggered() {

}
void MainWindow::on_actionEllipse_triggered() {

}
void MainWindow::on_actionColor_Picker_triggered() {

}
void MainWindow::on_actionEraser_triggered() {

}
