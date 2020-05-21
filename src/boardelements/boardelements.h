#ifndef BUTTON_H
#define BUTTON_H
#include <QString>

struct Button{
  QString name;
  QString action;
};

struct Slider{
  QString name;
  int from;
  int to;
};

#endif // BUTTON_H
