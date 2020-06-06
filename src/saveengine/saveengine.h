#ifndef SAVEENGINE_H
#define SAVEENGINE_H
#include <vector>
#include "../boardelements/boardelements.h"

class Saveengine
{
public:
    std::vector<Boardelement> GetFromFile(QString path);              //Funktion um von einer Datei(Board Datei) in einen Vector(Boardelement) zu laden, dieser wird dann returnt.
    void SaveToFile(QString path, std::vector<Boardelement> boardelements);
};

#endif // SAVEENGINE_H
