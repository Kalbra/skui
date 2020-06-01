#include "board.h"
#include "mainwindow.h"
#include "../fileio/fileio.h"
#include "../saveengine/saveengine.h"

#include <QJsonDocument>
#include <QLabel>

void Board::setup(){
    board = new QWidget();
}

void Board::setFile(QString path){
    p_path = path;
    update();
}

QWidget *Board::getBoard(){
    return board;
}

void Board::update(){
    QJsonDocument document = LoadJsonDocument(p_path);

    qDebug().noquote() << document.isEmpty();

    QLabel *label = new QLabel(board);

    label->setText(p_path);

    Saveengine saveengine;
    saveengine.GetFromFile(p_path);
}

