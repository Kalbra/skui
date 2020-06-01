#ifndef FILENAMEENGINE_H
#define FILENAMEENGINE_H
#include <vector>
#include <QString>
#include <QJsonArray>
#include <QDebug>

class Filenameengine
{
public:
    QString              currentboard;
    std::vector<QString> openboards;
    std::vector<QString> recentboard;

    void Setnewfile(QString file){
        openboards.push_back(file);
        currentboard = file;
    }

    void Savefilenames(){
        QJsonArray openboardsarray;
        for(int i = 0; i < openboards.size(); i++){
            openboardsarray.append(openboards[i]);
        }
        QJsonArray recentboardarray;
        for(int i = 0; i < recentboardarray.size(); i++){
            recentboardarray.append(recentboard[i]);
        }

        qDebug() << recentboardarray;
        qDebug() << openboardsarray;
    }
};

#endif // FILENAMEENGINE_H
