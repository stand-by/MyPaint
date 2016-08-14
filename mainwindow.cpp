#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    director = new Director(this);

    this->setWindowTitle("MyPaint");
    this->setCentralWidget(director->view);
}

MainWindow::~MainWindow() {
    delete director;
    delete ui;
}

void MainWindow::on_actionCursor_triggered() {
    this->setCursor(QCursor(Qt::ArrowCursor));
    director->setCursorTool();
}
void MainWindow::on_actionPencil_triggered() {
    this->setCursor(QCursor(QPixmap(":/icons/Pencil-24.png")));
    director->setPencilTool();
}
void MainWindow::on_actionLine_triggered() {
    this->setCursor(QCursor(QPixmap(":/icons/Line-24.png")));
    director->setLineTool();
}
void MainWindow::on_actionRectangle_triggered() {
    this->setCursor(QCursor(QPixmap(":/icons/Rectangle\ Stroked-24.png")));
    director->setRectangleTool();
}
void MainWindow::on_actionFilled_Rectangle_triggered() {
    this->setCursor(QCursor(QPixmap(":/icons/Rectangle-24.png")));
    director->setFilledRectangleTool();
}
void MainWindow::on_actionEllipse_triggered() {
    this->setCursor(QCursor(QPixmap(":/icons/Ellipse\ Stroked-24.png")));
    director->setEllipseTool();
}
void MainWindow::on_actionFilled_Ellipse_triggered() {
    this->setCursor(QCursor(QPixmap(":/icons/Ellipse-24.png")));
    director->setFilledEllipseTool();
}

void MainWindow::on_actionColor_Picker_triggered() {
    QColor color = QColorDialog::getColor(Qt::black, this, "Choose color for tool: ");
    if(color.isValid()) director->setToolColor(color);
}
void MainWindow::on_actionEraser_triggered() {
    this->setCursor(QCursor(QPixmap(":/icons/Delete-24.png")));
    director->setEraseTool();
}

void MainWindow::on_actionThicker_triggered() {

}
void MainWindow::on_actionThinner_triggered() {

}
