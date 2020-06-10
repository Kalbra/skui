#ifndef BOARD_H
#define BOARD_H
#include <QtCore>
#include <QMainWindow>
#include <QObject>

#include "../boardelements/boardelements.h"
#include "../serialio/serialio.h"
#include "../toolbar/toolbar.h"

class Board : public QObject
{
    Q_OBJECT

public:

    void setup(Toolbar *toolbar);
    void setFile(QString path);
    void update();

    QWidget *getBoard();

private slots:
    void changeSerialSettings();

private:
    QString p_path = "files.json";

    QWidget *board;

    Serialio *serial;

    Toolbar *p_toolbar;

    std::vector<Boardelement> boardelements;

    void PrintSerialById(int id, int value);




};

#endif // BOARD_H
