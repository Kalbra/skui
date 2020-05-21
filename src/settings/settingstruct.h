#ifndef SETTINGSTRUCT_H
#define SETTINGSTRUCT_H
#include <QtCore>
#include <vector>
#include "../boardelements/boardelements.h"

struct Settings{
    std::vector<Button, Slider> *elements;
};


#endif // SETTINGSTRUCT_H
