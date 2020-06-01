#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../boardelements/boardelements.h"
#include "board.h"
#include "../filenameengine/filenameengine.h"
#include "../filebar/filebar.h"
#include "../fileio/filedialog.h"
#include "../fileio/fileio.h"

#include <QtCore>
#include <QDockWidget>
#include <vector>
#include <QPushButton>

Filenameengine filenameengine;

Board voidboard;
Board *currentboard = &voidboard;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStyle *style = qApp->style();

    filebar = new Filebar();

    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::on_new_triggered);
    connect(ui->actionButton, &QAction::triggered, this, &MainWindow::on_button_triggered);
    connect(ui->actionSlider, &QAction::triggered, this, &MainWindow::on_slider_triggered);
}

MainWindow::~MainWindow(){
    filenameengine.Savefilenames();
    delete ui;
}

void MainWindow::on_new_triggered(){
    Board *board = new Board();
    currentboard = board;

    board->setup();

    QString url = OpenFileDialog(this);
    filenameengine.Setnewfile(url);
    board->setFile(filenameengine.currentboard);

    ui->boards->addTab(board->getBoard(), filenameengine.currentboard);

}

void MainWindow::resizeEvent(QResizeEvent* event)
{
   QMainWindow::resizeEvent(event);
   currentboard->update();
}

void MainWindow::on_button_triggered(){

}

void MainWindow::on_slider_triggered(){

}

void MainWindow::on_boards_tabCloseRequested(int index){
    ui->boards->removeTab(index);
}
