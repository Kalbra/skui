#ifndef FILEIO_H
#define FILEIO_H
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>

void SaveString(QString path, QString data);                          //Funktion um einen String zu Speichern(aus einer Datei)

QString LoadString(QString path);                                     //Funktion um einen String zu Laden(aus einer Datei)

void SaveJsonDocument(QString path, QJsonDocument document);          //Funktion um ein JsonDocument zu Speichern(aus einer Datei)

QJsonDocument LoadJsonDocument(QString path);                         //Funktion um einen JsonDocument zu Laden(aus einer Datei)

#endif // FILEIO_H
