#include "saveengine.h"
#include "serialgui.h"
#include <QtCore>
#include <fstream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <vector>

QJsonDocument FileToJson(QString path){
    QFile file(path);

    if(!file.open(QIODevice::ReadOnly)){}

    QTextStream instream(&file);
    QString content = instream.readAll();

    file.close();

    return QJsonDocument::fromJson(content.toUtf8());;
}

void JsonToFile(QString path, QString json){
    QFile file(path);
    file.open(QIODevice::WriteOnly);

    if(!file.isOpen()){
        qDebug() << "fileerror";
    }

    QTextStream outstream(&file);

    outstream << json;

    file.close();
}

void SaveButtonsToFile(QString path){
    QJsonArray buttonarray;

    for(int i = 0; i < buttons.size(); i++){
        QJsonObject model {
            {"mode", buttons[i].mode},
            {"send", buttons[i].send}
        };

        buttonarray.append(model);
    }

    QJsonDocument jsontofile(buttonarray);

    JsonToFile(path, jsontofile.toJson());
}

void LoadButtonsfromFile(QString path){
    QJsonDocument json        = FileToJson(path);
    QJsonObject   jsonobject  = json.object();
    QJsonArray    buttonarray = json.array();

    for(int i = 0; i < buttonarray.size(); i++){
        QJsonObject button = buttonarray[i].toObject();
        QJsonValue mode = button.value("mode");
        QJsonValue send = button.value("send");

        ButtonElement model;

        model.mode = mode.toInt();
        model.send = send.toString();

        buttons.push_back(model);

    }

    qDebug().noquote() << buttonarray[1];
    qDebug() << buttonarray.size();
}
