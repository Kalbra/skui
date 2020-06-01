#ifndef BUTTON_H
#define BUTTON_H
#include <QString>

class Boardelement
{
public:
    QString name;
};


class Button : public Boardelement
{
public:
    QString action;
};

class Slider : public Boardelement
{
public:
    int from;
    int to;
};



#endif // BUTTON_H
