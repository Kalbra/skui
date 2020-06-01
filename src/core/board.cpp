#include "board.h"
#include "mainwindow.h"
#include "../fileio/fileio.h"
#include "../saveengine/saveengine.h"

#include <QJsonDocument>
#include <QPushButton>
#include <QLabel>

void Board::setup(){
    board = new QWidget();
}

void Board::setFile(QString path){
    p_path = path;

    Saveengine saveengine;
    boardelements = saveengine.GetFromFile(p_path);

    update();
}

QWidget *Board::getBoard(){
    return board;
}

void Board::update(){
    int xbefor = 0;
    int ybefor = 0;
    //int widgetwidth = board->width();

    //qDeleteAll(board->findChildren<QWidget*>("", Qt::FindDirectChildrenOnly));

    //qDebug() << "Update: " << this;
    QJsonDocument document = LoadJsonDocument(p_path);

    qDebug() << boardelements.size();

    for(int i = 0; i < boardelements.size(); i++){
        qDebug() << board->width();
        if((0 - xbefor) < 100){
            xbefor = 0;
            ybefor = ybefor + 100;
        }

        Boardelement boardelement = boardelements[i];
        QString eventtype = boardelement.type;

        if(eventtype == "button"){
            QPushButton *button = new QPushButton(board);
            button->setGeometry(xbefor, ybefor, 100, 100);
            button->setText(boardelement.name);

            xbefor = xbefor + 100;
        }
    }
}

