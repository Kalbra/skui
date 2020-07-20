#include "serialio.h"

#include <QDebug>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>

Serialio::Serialio(QString port, int baudrate){
    p_port     = port;
    p_baudrate = baudrate;
}

QList<QSerialPortInfo> Serialio::getPorts(){
    return QSerialPortInfo::availablePorts();
}

void Serialio::setPort(QString port){
    p_port     = port;
}

void Serialio::setBaudRate(int baudrate){
    p_baudrate = baudrate;
}

void Serialio::send(QString str){
    //Init the Serialport
    QSerialPort serial;
    serial.setPortName(p_port);
    serial.setBaudRate(p_baudrate);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.open(QIODevice::ReadWrite);

    //Write to serial
    serial.write(str.toUtf8());


    //Debuging to see whats happening
    qDebug() << "Virtual Serial on" << p_port << p_baudrate << " ::  " << str;
}
