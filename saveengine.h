#ifndef SAVEENGINE_H
#define SAVEENGINE_H
#include <QtCore>
#include <QJsonDocument>
#include "serialgui.h"
#include <vector>


void LoadButtonsfromFile(QString path);                               //Lädt aus der Datei in den Array(buttons)

void SaveButtonsToFile(QString path);                                 //Funktion um den Button Array erst zu jsonifizieren und dann in die Datei schreiben



#endif // SAVEENGINE_H
