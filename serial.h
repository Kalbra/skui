#ifndef SERIAL_H
#define SERIAL_H
#include <QtCore>
#include <QtSerialPort/QSerialPortInfo>
#include "generalsettings.h"


class Serial : public QObject
{
    Q_OBJECT

public:
    void WriteToSerial(Generalsettings *settings, QString data);
    QList<QSerialPortInfo> FindPorts();
};

#endif // SERIAL_H
