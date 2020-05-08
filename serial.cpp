#include "serial.h"
#include <QtCore>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>

QList<QSerialPortInfo> Serial::FindPorts(){
    return QSerialPortInfo::availablePorts();
}


void Serial::WriteToSerial(QString data){
    QSerialPort serial;
    serial.setPortName(portname);
    serial.setBaudRate(baudrade);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.open(QIODevice::ReadWrite);

    serial.write(data.toUtf8());
}
