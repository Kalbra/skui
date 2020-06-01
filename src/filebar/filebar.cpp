#include "filebar.h"
#include "../filenameengine/filenameengine.h"
#include <QPushButton>
#include <QHBoxLayout>
#include "../core/mainwindow.h"

#define BUTTONGROUPSTYLE "background-color: gray; border: 2px solid black; padding: 5px;"
#define BUTTONNAMESTYLE  "padding-top: 5px; padding-bottom: 5px; color: black; border: none;"
#define BUTTONCLOSESTYLE "color: red; margin: 0px; border: none;"



QWidget* Filebar::addTab(Filenameengine *filenameengine){
    QWidget *widget  = new QWidget();
    widget->setStyleSheet(BUTTONGROUPSTYLE);

    QPushButton *tab = new QPushButton("$NAME");
    tab->setStyleSheet(BUTTONNAMESTYLE);

    QPushButton *del = new QPushButton("X");
    del->setMaximumSize(20, 20);
    del->setStyleSheet(BUTTONCLOSESTYLE);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(0);
    layout->addWidget(tab);
    layout->addWidget(del);

    widget->setLayout(layout);
    widget->setMaximumSize(200, 20);

    return widget;
}
