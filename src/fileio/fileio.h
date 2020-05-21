#ifndef FILEIO_H
#define FILEIO_H
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>

void SaveString(QString path, QString data){
    QFile file(path);                                                 //Definiert die Datei

    if(!file.open(QIODevice::WriteOnly)){}                            //Error, aber noch kein Inhalt

    QTextStream outstream(&file);                                     //Definiert den TextStream
    outstream << data;                                                //Schreibt den String in die Datei

    file.close();                                                     //Schließt die Datei
}

QString LoadString(QString path){
    QFile file(path);                                                 //Definiert die Datei

    if(!file.open(QIODevice::ReadOnly)){}                             //Error, aber noch kein Inhalt

    QTextStream instream(&file);                                      //Definiert den TextStream
    QString content = instream.readAll();                             //Liest den Stream und speichert ihn in einem QString

    file.close();                                                     //Schließt die Datei

    return content;                                                   //Returnt den String
}




#endif // FILEIO_H
