#ifndef BOARD_H
#define BOARD_H
#include <QtCore>
#include <QMainWindow>

#include "mainwindow.h"

class Board
{
    Q_OBJECT

public:
    Board();
    void setup();

    void setFile(QString path);

    void update();

    QWidget *getBoard();

private:
    QString p_path = "content.json";

    QWidget *board;
};

#endif // BOARD_H
