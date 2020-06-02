#ifndef BOARD_H
#define BOARD_H
#include <QtCore>
#include <QMainWindow>

//#include "mainwindow.h"
#include "../boardelements/boardelements.h"

class Board
{
public:

    void setup();
    void setFile(QString path);
    void update();

    QWidget *getBoard();

private:
    QString p_path = "files.json";

    QWidget *board;

    std::vector<Boardelement> boardelements;

    void PrintSerialById(int id);
};

#endif // BOARD_H
