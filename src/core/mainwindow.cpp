#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../boardelements/boardelements.h"

#include <QtCore>
#include <QDockWidget>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDockWidget *test = new QDockWidget("Select Widget", this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

