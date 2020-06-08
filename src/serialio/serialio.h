#ifndef SERIALIO_H
#define SERIALIO_H
#include <QString>
#include <QtSerialPort/QSerialPortInfo>

class Serialio
{
public:
    Serialio(QString port, int baudrate);                             //Klass Constructur der den Port braucht und die Baudrate(nicht Verflichtend Standardwert: 9600)

    static QList<QSerialPortInfo> getPorts();                                //Funktion um die verfügbaren Ports in eine QList(Vector) zu schreiben, diese wird dann returnt

    void setPort(QString port);                                       //Funktion um den Port zu ändern
    void setBaudRate(int baudrate);                                   //Funktion um die Baudrate zu setzen (oder zu ändern)

    void send(QString str);                                           //Funktion um einen String zu senden

private:
    QString p_port;
    int p_baudrate;
};

#endif // SERIALIO_H
