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

    std::vector<Buttonelement> event;
};

#endif // BOARD_H
