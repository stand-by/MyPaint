#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    director = new Director(this);

    this->setWindowTitle("MyPaint");
    this->setCentralWidget(director->view);
}

MainWindow::~MainWindow() {
    delete ui;
    delete director;
}
