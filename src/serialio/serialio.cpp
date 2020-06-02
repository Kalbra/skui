#include "serialio.h"

#include <QDebug>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>

Serialio::Serialio(QString port, int baudrate = 9600){
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
    QSerialPort serial;
    serial.setPortName(p_port);
    serial.setBaudRate(p_baudrate);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.open(QIODevice::ReadWrite);

    serial.write(str.toUtf8());

    qDebug() << "Virtual Serial on" << p_port << p_baudrate << " ::  " << str;
}
