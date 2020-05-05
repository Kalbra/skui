#include "serialgui.h"                                                //Bindet die eingene Headerdatei ein
#include <QApplication>                                               //Bindet QApplication ein um die App zu starten

int main(int argc, char *argv[])                                      //Erste Funktion die Ausgeführt wird
{
    QApplication a(argc, argv);                                       //Definiert die Anwendeung und übergibt Terminal Argumente
    Serialgui w;                                                      //Definiert das Main Window
    w.show();                                                         //Strartet bzw. zeigt das Main Window
    return a.exec();                                                  //Returnt die Funktion a.exec
}
