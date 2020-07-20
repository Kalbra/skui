#include "toolbar.h"
#include "../serialio/serialio.h"

#include <QWidget>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QComboBox>
#include <QList>
#include <QSerialPortInfo>
#include <QTimer>
#include <QDebug>
#include <QObject>

Toolbar::Toolbar(){
    p_toolbar = new QWidget();

    p_ports = new QComboBox(p_toolbar);

    p_baudratespinbox = new QSpinBox(p_toolbar);
    p_baudratespinbox->setMaximum(115200);
    p_baudratespinbox->setMinimum(75);
    p_baudratespinbox->setValue(9600);

    QHBoxLayout* layout = new QHBoxLayout(p_toolbar);
    layout->setMargin(0);
    layout->addWidget(p_baudratespinbox);
    layout->addWidget(p_ports);

    QTimer *updatetimer = new QTimer(this);
    connect(updatetimer, SIGNAL(timeout()), this, SLOT(update()));
    updatetimer->start(1000);

    connect(p_ports, SIGNAL(currentTextChanged(QString)), this, SLOT(portnameChanged(QString)));
    connect(p_baudratespinbox, SIGNAL(valueChanged(int)), this, SLOT(baudrateChanged(int)));

}

void Toolbar::update(){
    QList<QSerialPortInfo> availableports = Serialio::getPorts();

    p_ports->clear();

    for(int i = 0; i < availableports.size(); i++){
        p_ports->addItem(availableports[i].portName());
    }
}

void Toolbar::baudrateChanged(int rate){
    p_baudrate = rate;
    emit settingsChanged();
}

void Toolbar::portnameChanged(QString text){
    if(text != ""){
        if(text != p_portname){
            p_portname = text;
            emit settingsChanged();
        }
    }
}

int Toolbar::getBaud(){
    return p_baudrate;
}

QString Toolbar::getPort(){
    return p_portname;
}

QWidget *Toolbar::getToolbar(){
    return p_toolbar;
}
