#ifndef BOARD_H
#define BOARD_H
#include <QtCore>
#include <QMainWindow>
#include <QObject>

#include "../boardelements/boardelements.h"
#include "../serialio/serialio.h"

class Board : public QObject
{
    Q_OBJECT

public:

    void setup();
    void setFile(QString path);
    void update();

    QWidget *getBoard();

private:
    QString p_path = "files.json";

    QWidget *board;

    Serialio *serial;

    std::vector<Boardelement> boardelements;

    void PrintSerialById(int id);
};

#endif // BOARD_H
