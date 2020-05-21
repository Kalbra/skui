#ifndef FILEIO_H
#define FILEIO_H
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>

void SaveString(QString path, QString data){                          //Funktion um einen String zu Speichern(aus einer Datei)
    QFile file(path);                                                 //Definiert die Datei

    if(!file.open(QIODevice::WriteOnly)){}                            //Error, aber noch kein Inhalt

    QTextStream outstream(&file);                                     //Definiert den TextStream
    outstream << data;                                                //Schreibt den String in die Datei

    file.close();                                                     //Schließt die Datei
}

QString LoadString(QString path){                                     //Funktion um einen String zu Laden(aus einer Datei)
    QFile file(path);                                                 //Definiert die Datei

    if(!file.open(QIODevice::ReadOnly)){}                             //Error, aber noch kein Inhalt

    QTextStream instream(&file);                                      //Definiert den TextStream
    QString content = instream.readAll();                             //Liest den Stream und speichert ihn in einem QString

    file.close();                                                     //Schließt die Datei

    return content;                                                   //Returnt den String
}

void SaveJsonDocument(QString path, QJsonDocument document){          //Funktion um ein JsonDocument zu Speichern(aus einer Datei)
    SaveString(path, document.toJson(QJsonDocument::Compact));        //Macht aus dem Document ein String und ruft dann SaveString() auf
}

QJsonDocument LoadJsonDocument(QString path){                         //Funktion um einen JsonDocument zu Laden(aus einer Datei)
    return QJsonDocument::fromJson(LoadString(path).toUtf8());        //Lädt den einen String mit LoadString() convertet ihn in ein JsonDocument und retrunt ihn dann
}



#endif // FILEIO_H
