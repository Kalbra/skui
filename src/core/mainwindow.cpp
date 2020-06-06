#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../boardelements/boardelements.h"
#include "board.h"
#include "../filenameengine/filenameengine.h"
#include "../fileio/filedialog.h"
#include "../fileio/fileio.h"
#include "../boardeditor/boardeditor.h"

#include <QtCore>
#include <QDockWidget>
#include <vector>
#include <QPushButton>

Filenameengine filenameengine;

Board voidboard;
Board *currentboard;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //File
    connect(ui->actionNew,    &QAction::triggered, this, &MainWindow::on_new_triggered);
    connect(ui->actionOpen,   &QAction::triggered, this, &MainWindow::on_open_triggered);

    //Edit
    connect(ui->actionBoardeditor, &QAction::triggered, this, &MainWindow::on_boardeditor_triggered);
    connect(ui->actionSlider, &QAction::triggered, this, &MainWindow::on_slider_triggered);

    //View
    connect(ui->actionReload, &QAction::triggered, this, &MainWindow::on_reload_triggered);

    voidboard.setup();
    currentboard = &voidboard;
}

MainWindow::~MainWindow(){
    filenameengine.Savefilenames();
    delete ui;
}

void MainWindow::on_new_triggered(){

}

void MainWindow::on_open_triggered(){
    Board *board = new Board();
    currentboard = board;

    board->setup();

    QString url = OpenFileDialog(this);
    if(url != ""){
        filenameengine.Setnewfile(url);
        board->setFile(filenameengine.currentboard);

        ui->boards->addTab(board->getBoard(), filenameengine.currentboard);
        ui->boards->setCurrentWidget(board->getBoard());

        currentboard->update();
    }
}

void MainWindow::on_reload_triggered(){
    currentboard->setFile(filenameengine.currentboard);
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
   QMainWindow::resizeEvent(event);
   currentboard->update();
}

void MainWindow::on_boardeditor_triggered(){
    Boardeditor *boardeditor = new Boardeditor();
    ui->boards->addTab(boardeditor->getBoardeditor(), "New...");
    ui->boards->setCurrentWidget(boardeditor->getBoardeditor());

}

void MainWindow::on_slider_triggered(){

}

void MainWindow::on_boards_tabCloseRequested(int index){
    ui->boards->removeTab(index);
}
