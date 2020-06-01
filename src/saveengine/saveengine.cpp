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

        if(eventtype == "button"){                                    //Wenn der Eventtype gleich button ist
            Button button;                                            //Erstellt einen neuen Button
            button.name   = element.value("name")  .toString();       //Übergibt den Namen für den Button
            button.action = element.value("action").toString();       //Übergibt die Aktion, die ausgeführt werden soll

            boardelements.push_back(button);                          //Hängt den Button an das Ende des Vectors(boardelements) an
        }
        else if(eventtype == "slider"){                               //Wenn der Eventtype gleich slider ist
            Slider slider;                                            //Erstellt einen neuen Slider
            slider.name   = element.value("name").toString();         //Übergibt den Namen für den Slider
            slider.from   = element.value("from").toInt();            //Übergibt die From value für den Slider
            slider.to     = element.value("to")  .toInt();            //Übergibt die To value für dne Slider

            boardelements.push_back(slider);                          //Hängt den Slider an das Ende des Vectors(boardelements) an
        }
    }

    return boardelements;                                             //Returnt den Vector(boardelements)
}
