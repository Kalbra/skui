#include "saveengine.h"
#include "../fileio/fileio.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

std::vector<Boardelement> Saveengine::GetFromFile(QString path){
    std::vector<Boardelement> boardelements;

    QJsonDocument document = LoadJsonDocument(path);
    QJsonArray    array    = document.array();

    //qDebug() << document.toJson();

    for(int i = 0; i < array.size(); i++){
        QJsonObject element = array[i].toObject();

        QString eventtype = element.value("type").toString();

        if(eventtype == "button"){
            Button button;
            button.name   = element.value("name")  .toString();
            button.action = element.value("action").toString();

            boardelements.push_back(button);
        }
        else if(eventtype == "slider"){
            Slider slider;
            slider.name   = element.value("name").toString();
            slider.from   = element.value("from").toInt();
            slider.to     = element.value("to")  .toInt();

            boardelements.push_back(slider);
        }
    }


    return boardelements;
}
