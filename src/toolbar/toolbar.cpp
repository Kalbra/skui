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

    QSpinBox *baudrate = new QSpinBox(p_toolbar);
    baudrate->setMaximum(115200);
    baudrate->setMinimum(75);
    baudrate->setValue(9600);

    QHBoxLayout* layout = new QHBoxLayout(p_toolbar);
    layout->setMargin(0);
    layout->addWidget(baudrate);
    layout->addWidget(p_ports);

    QTimer *updatetimer = new QTimer(this);
    qDebug() << connect(updatetimer, SIGNAL(timeout()), this, SLOT(update()));
    updatetimer->start(1000);
}

void Toolbar::update(){
    QList<QSerialPortInfo> availableports = Serialio::getPorts();

    p_ports->clear();

    for(int i = 0; i < availableports.size(); i++){
        p_ports->addItem(availableports[i].portName());
    }
}


QWidget *Toolbar::getToolbar(){
    return p_toolbar;
}
