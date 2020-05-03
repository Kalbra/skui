#include "serialgui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Serialgui w;
    w.show();
    return a.exec();
}
