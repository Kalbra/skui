#ifndef FILEIO_H
#define FILEIO_H
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>

void SaveString(QString path, QString data);

QString LoadString(QString path);

void SaveJsonDocument(QString path, QJsonDocument document);

QJsonDocument LoadJsonDocument(QString path);

#endif // FILEIO_H
