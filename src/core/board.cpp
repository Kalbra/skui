#include "board.h"
#include "mainwindow.h"
#include "../fileio/fileio.h"
#include <QJsonDocument>

Board::Board(){

}

void Board::setup(){
    board = new QWidget();
}

void Board::setFile(QString path){
    p_path = path;
}

QWidget *Board::getBoard(){
    return board;
}

void Board::update(){
    QJsonDocument document = LoadJsonDocument(p_path);
}

