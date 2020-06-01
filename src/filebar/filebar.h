#ifndef FILEBAR_H
#define FILEBAR_H
#include <QWidget>
#include "../filenameengine/filenameengine.h"

class Filebar
{
    //Q_OBJECT

public:
    QWidget* addTab(Filenameengine *filenameengine);


};

#endif // FILEBAR_H
