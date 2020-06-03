#include "board.h"
#include "mainwindow.h"
#include "../fileio/fileio.h"
#include "../saveengine/saveengine.h"
#include "../serialio/serialio.h"
#include "../boardelements/boardelements.h"

#include <QJsonDocument>
#include <QObject>
#include <QPushButton>
#include <QSlider>
#include <QLabel>



void Board::setup(){
    board  = new QWidget();
    serial = new Serialio("/dev/ttyUSB0", 9600);
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

void Board::PrintSerialById(int id){
    QString eventtype = boardelements[id].type;

    if(eventtype == "button"){
        Button *button = static_cast<Button*>(&boardelements[id]);
        qDebug() << button->name;
        serial->send(button->action);
    }
    else if(eventtype == "slider"){
        Slider *slider = static_cast<Slider*>(&boardelements[id]);
        serial->send(QString::number(slider->to));
    }

    qDebug() << boardelements[id].name;
}

void Board::update(){
    int xbefor = 0;
    int ybefor = 0;
    int widgetwidth = board->width();

    qDeleteAll(board->children());

    QJsonDocument document = LoadJsonDocument(p_path);

    for(int i = 0; i < boardelements.size(); i++){

        if((widgetwidth - xbefor) < 100){
            xbefor = 0;
            ybefor = ybefor + 100;
        }

        Boardelement boardelement = boardelements[i];
        QString eventtype = boardelement.type;

        if(eventtype == "button"){
            QPushButton *button = new QPushButton(board);
            button->setGeometry(xbefor, ybefor, 100, 100);
            button->setText(boardelement.name);

            connect(button, &QPushButton::clicked, this, [=]{ PrintSerialById(i); });

            button->show();

            xbefor = xbefor + 100;
        }
        else if(eventtype == "slider"){
            QSlider *slider = new QSlider(board);
            slider->setGeometry(xbefor, ybefor, 100, 100);

            slider->show();

            xbefor = xbefor + 100;
        }
    }
}

