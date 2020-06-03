#include "saveengine.h"
#include "../fileio/fileio.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

std::vector<Boardelement> Saveengine::GetFromFile(QString path){      //Funktion um von einer Datei(Board Datei) in einen Vector(Boardelement) zu laden, dieser wird dann returnt.
    std::vector<Boardelement> boardelements;                          //Definiert den Vetor der Klasse Boardelement(siehe: boardelements.h)

    QJsonDocument document = LoadJsonDocument(path);                  //Nimmt mit der Funktion LoadJsonDocument() das QJsonDocunent und speichert es in document
    QJsonArray    array    = document.array();                        //Konvertiert document zu einem Array in array

    for(int i = 0; i < array.size(); i++){                            //For Schleife um aus dem Array die Elemente zu extrahieren
        QJsonObject element = array[i].toObject();                    //Speichert das jetzige Elemten in der Variable element

        QString eventtype = element.value("type").toString();         //Extrahiert aus dem element das Keyword type und Konvertiert es in einen String

        Boardelement boardelement;
        boardelement.name   = element.value("name")  .toString();
        boardelement.type   = element.value("type")  .toString();
        boardelement.action = element.value("action").toString();

        if(eventtype == "slider"){
            boardelement.from = element.value("from").toInt();
            boardelement.to   = element.value("to")  .toInt();
        }

        boardelements.push_back(boardelement);
    }

    return boardelements;                                             //Returnt den Vector(boardelements)
}
