#ifndef SERIAL_H
#define SERIAL_H
#include <QtCore>
#include <QtSerialPort/QSerialPortInfo>


class Serial : public QObject
{
    Q_OBJECT

    int baudrade;
    QString portname;


public:
    void WriteToSerial(QString data);
    QList<QSerialPortInfo> FindPorts();


};

#endif // SERIAL_H
