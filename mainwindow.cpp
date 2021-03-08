#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(1280, 720);
    this->myWidget = new MyWidget();
    this->setCentralWidget(this->myWidget);
}

MainWindow::~MainWindow()
{
    if(this->myWidget) {
        delete myWidget;
    }
}

