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

using namespace ads;

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

    //View
    connect(ui->actionReload, &QAction::triggered, this, &MainWindow::on_reload_triggered);

    p_toolbar = new Toolbar();


    //Write a emty board in currentboard provent crashes
    voidboard.setup(p_toolbar);
    currentboard = &voidboard;

    //Init the Dockmanager
     m_DockManager = new CDockManager(this);

     //Adds a toolbar
     CDockWidget *toolbar = new CDockWidget("Toolbar");
     toolbar->setWidget(p_toolbar->getToolbar());
     toolbar->resize(toolbar->width(), 20);

     m_DockManager->addDockWidget(TopDockWidgetArea, toolbar);


     CDockWidget *welcome = new CDockWidget("Welcome");

     Welcome welcomemsg;
    welcome->setWidget(welcomemsg.engine());

    m_DockManager->addDockWidget(BottomDockWidgetArea, welcome);

}

MainWindow::~MainWindow(){
    //Saves the filenames before quit the application
    filenameengine.Savefilenames();
    delete ui;
}


void MainWindow::on_new_triggered(){
    //Init a new Boardeditor
    Boardeditor *boardeditor = new Boardeditor();

    //Add the Boardeditor to the docksystem
    CDockWidget *dockwidget = new CDockWidget("New ...");
    dockwidget->setWidget(boardeditor->getBoardeditor());
    m_DockManager->addDockWidgetTab(BottomDockWidgetArea, dockwidget);
}

void MainWindow::on_open_triggered(){
    //Creates a board
    Board *board = new Board();
    //Set the currentboard
    currentboard = board;

    //Run the setup process
    board->setup(p_toolbar);

    //Making a filedialog for the files to be opened
    QString url = FileDialog::OpenFileDialog(this);

    //Ignore canceling
    if(url != ""){
        //Tells to the filenameengine the new filename
        filenameengine.Setnewfile(url);

        //Sets the file
        board->setFile(filenameengine.currentboard);

        //Add the Board to the docksystem
        CDockWidget *dockwidget = new CDockWidget(filenameengine.currentboard);
        dockwidget->setWidget(currentboard->getBoard());

        m_DockManager->addDockWidgetTab(BottomDockWidgetArea, dockwidget);

        //Updates (in this case init) the currentboard
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
    //Ignore triggerring without file
    if(filenameengine.currentboard != ""){
        //Making a Boardeditor
        Boardeditor *boardeditor = new Boardeditor();
        boardeditor->setFile(filenameengine.currentboard);
        boardeditor->loadFile();

        //Makeing a dock tab
        CDockWidget *boardeditordock = new CDockWidget("Edit: "+ filenameengine.currentboard);
        boardeditordock->setWidget(boardeditor->getBoardeditor());

        //Add the tab to dockmanager
        m_DockManager->addDockWidgetTab(BottomDockWidgetArea, boardeditordock);
    }
}
