#ifndef SAVEENGINE_H
#define SAVEENGINE_H
#include <vector>
#include "../boardelements/boardelements.h"

class Saveengine
{
public:
    std::vector<Buttonelement> GetFromFile(QString path);
};

#endif // SAVEENGINE_H
