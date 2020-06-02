#include "serialio.h"

#include <QDebug>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>

Serialio::Serialio(QString port, int baudrate = 9600){                //Klass Constructur der den Port braucht und die Baudrate(nicht Verflichtend Standardwert: 9600)
    p_port     = port;                                                //Übergibt den port in die privatevalue p_port
    p_baudrate = baudrate;                                            //Übergibt den baudrate in die privatevalue p_baudrate
}

QList<QSerialPortInfo> Serialio::getPorts(){                          //Funktion um die verfügbaren Ports in eine QList(Vector) zu schreiben, diese wird dann returnt
    return QSerialPortInfo::availablePorts();                         //Holt die verfügbaren Ports und returnt sie dann
}

void Serialio::setPort(QString port){                                 //Funktion um den Port zu ändern
    p_port     = port;                                                //Übergibt den port in die privatevalue p_port
}

void Serialio::setBaudRate(int baudrate){                             //Funktion um die Baudrate zu setzen (oder zu ändern)
    p_baudrate = baudrate;                                            //Übergibt den baudrate in die privatevalue p_baudrate
}

void Serialio::send(QString str){                                     //Funktion um einen String zu senden
    QSerialPort serial;                                               //Definiert den QSerialPort (serial)
    serial.setPortName(p_port);                                       //Setzt den Portname
    serial.setBaudRate(p_baudrate);                                   //Setzt die Baudrate
    serial.setDataBits(QSerialPort::Data8);                           //Setzt Serialeinstellung
    serial.setParity(QSerialPort::NoParity);                          //Setzt Serialeinstellung
    serial.setStopBits(QSerialPort::OneStop);                         //Setzt Serialeinstellung
    serial.setFlowControl(QSerialPort::NoFlowControl);                //Setzt Serialeinstellung
    serial.open(QIODevice::ReadWrite);                                //Öffnet den Serialport

    serial.write(str.toUtf8());                                       //Schreibt den String

    qDebug() << "Virtual Serial on" << p_port << p_baudrate << " ::  " << str;  //Debugfunktion (beinhaltet den Portname, Baudrate und den zu sendenen String)
}
