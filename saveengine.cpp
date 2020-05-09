#include "saveengine.h"
#include "serialgui.h"
#include <QtCore>
#include <fstream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <vector>

QJsonDocument FileToJson(QString path){                               //Funktion um eine Datei in ein Jsondocument zu laden(wird dann returnt)
    QFile file(path);                                                 //Definiert die Datei

    if(!file.open(QIODevice::ReadOnly)){}                             //Error, aber noch kein Inhalt

    QTextStream instream(&file);                                      //Definiert den TextStream
    QString content = instream.readAll();                             //Liest den Stream und speichert ihn in einem QString

    file.close();                                                     //Schließt die Datei

    return QJsonDocument::fromJson(content.toUtf8());;                //Returnt das Document
}

void JsonToFile(QString path, QString json){                          //Funktion um einen Jsonstring in eine Datei zu speichern
    QFile file(path);                                                 //Definiert die Datei

    if(!file.open(QIODevice::WriteOnly)){}                            //Error, aber noch kein Inhalt

    QTextStream outstream(&file);                                     //Definiert den TextStream

    outstream << json;                                                //Schreibt den Jsonstring in die Datei

    file.close();                                                     //Schließt die Datei
}

void SaveButtonsToFile(QString path){                                 //Funktion um den Button Array erst zu jsonifizieren und dann in die Datei schreiben
    QJsonArray buttonarray;                                           //Definiert den Buttonarray, in welchen die Jsondatein aus dem Array geschreiben werden

    for(int i = 0; i < buttons.size(); i++){                          //For Schleife um den Array(buttons) in einzelenen Elementen zu haben
        QJsonObject model {                                           //Definiert das Jsonobjekt in welchen alle Daten eines Buttons gespeichert sind
            {"mode", buttons[i].mode},                                //Definiert den Mode als Json Element
            {"send", buttons[i].send},                                //Definiert den Send als Json Element
            {"name", buttons[i].name},                                //Definiert den Name als Json Element
            {"to",     buttons[i].to},
            {"from", buttons[i].from}
        };

        buttonarray.append(model);                                    //Führt das Model(für einen Button) in den Buttonarray
    }

    QJsonDocument jsontofile(buttonarray);                            //Konvertiert den Jsonarray in ein Jsondocument

    JsonToFile(path, jsontofile.toJson());                            //Führt die Funktion aus, welche den Jsonstring in eine Datei schreibt
}

void LoadButtonsfromFile(QString path){                               //Lädt aus der Datei in den Array(buttons)
    QJsonDocument json        = FileToJson(path);                     //Holt aus der Datei das Jsondocument durch FileToJson
    QJsonArray    buttonarray = json.array();                         //Konvertiert das Jsondocument in einen Jsonarray

    buttons.clear();                                                  //Claert den Buttonarray um vertoppelungen zu verhindern

    for(int i = 0; i < buttonarray.size(); i++){                      //For Schleife um den Jsonarray in einzelenen Elementen zu haben
        QJsonObject button = buttonarray[i].toObject();               //Konvertiert den jetzigen Array in ein Object
        QJsonValue mode = button.value("mode");                       //Extrahiert den Mode und schreibt ihn in eine JsonValue variable
        QJsonValue send = button.value("send");                       //Extrahiert den Send und schreibt ihn in eine JsonValue variable
        QJsonValue name = button.value("name");                       //Extrahiert den Name und schreibt ihn in eine JsonValue variable
        QJsonValue from = button.value("from");                       //Extrahiert den Name und schreibt ihn in eine JsonValue variable
        QJsonValue to   = button.value("to");                         //Extrahiert den Name und schreibt ihn in eine JsonValue variable

        ButtonElement model;                                          //Definert ein Buttonelement(Datentype für buttons)

        model.mode = mode.toInt();                                    //Übergibt die Jsonvalue Mode in das Button Element
        model.send = send.toString();                                 //Übergibt die Jsonvalue Mode in das Button Element
        model.name = name.toString();                                 //Übergibt die Jsonvalue Mode in das Button Element
        model.from = from.toInt();
        model.to   = to  .toInt();

        buttons.push_back(model);                                     //Hängt hinten an buttons das Button Element an

    }
}
