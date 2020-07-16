#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../boardelements/boardelements.h"
#include "board.h"
#include "../filenameengine/filenameengine.h"
#include "../fileio/filedialog.h"
#include "../fileio/fileio.h"
#include "../boardeditor/boardeditor.h"
#include "../toolbar/toolbar.h"
#include "../dock/DockManager.h"
#include "../welcome/welcome.h"

#include <QtCore>
#include <QDockWidget>
#include <vector>
#include <QPushButton>
#include <QWidget>
#include <QLabel>


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

    p_toolbar = new Toolbar();

    ui->boards->setCornerWidget(p_toolbar->getToolbar(), Qt::TopRightCorner);

    voidboard.setup(p_toolbar);
    currentboard = &voidboard;


     //Fügt die Toolbar hinzu
     CDockWidget *toolbar = new CDockWidget("Toolbar");
     toolbar->setWidget(p_toolbar->getToolbar());
     toolbar->resize(toolbar->width(), 10);

     m_DockManager->addDockWidget(TopDockWidgetArea, toolbar);

     CDockWidget *welcome = new CDockWidget("Welcome");
    welcome->setWidget(WelcomeMessage());

    m_DockManager->addDockWidget(TopDockWidgetArea, welcome);

}

MainWindow::~MainWindow(){
    filenameengine.Savefilenames();
    delete ui;
}

void MainWindow::on_new_triggered(){
    Boardeditor *boardeditor = new Boardeditor();

    qDebug() << "rsalkjdf";

    CDockWidget *dockwidget = new CDockWidget("New ...");
    dockwidget->setWidget(boardeditor->getBoardeditor());

//    ui->boards->addTab(boardeditor->getBoardeditor(), "New...");
//    ui->boards->setCurrentWidget(boardeditor->getBoardeditor());

    m_DockManager->addDockWidget(TopDockWidgetArea, dockwidget);
}

void MainWindow::on_open_triggered(){
    Board *board = new Board();
    currentboard = board;

    board->setup(p_toolbar);

    QString url = FileDialog::OpenFileDialog(this);
    qDebug() << "1";
    if(url != ""){
        filenameengine.Setnewfile(url);
        board->setFile(filenameengine.currentboard);

        ui->boards->addTab(board->getBoard(), filenameengine.currentboard);
        ui->boards->setCurrentWidget(board->getBoard());

        m_DockManager->addDockWidget(TopDockWidgetArea, dockwidget);

//        ui->boards->addTab(board->getBoard(), filenameengine.currentboard);
//        ui->boards->setCurrentWidget(board->getBoard());

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
    if(filenameengine.currentboard != ""){
        Boardeditor *boardeditor = new Boardeditor();
        boardeditor->setFile(filenameengine.currentboard);
        boardeditor->loadFile();
        ui->boards->addTab(boardeditor->getBoardeditor(), filenameengine.currentboard);
        ui->boards->setCurrentWidget(boardeditor->getBoardeditor());
    }
}

void MainWindow::on_slider_triggered(){

}

void MainWindow::on_boards_tabCloseRequested(int index){
    ui->boards->removeTab(index);
}
