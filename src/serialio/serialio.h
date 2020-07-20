#ifndef SERIALIO_H
#define SERIALIO_H
#include <QString>
#include <QtSerialPort/QSerialPortInfo>

class Serialio
{
public:
    explicit Serialio(QString port = "/dev/ttyUSB0", int baudrate = 9600);

    //Returns all available ports
    static QList<QSerialPortInfo> getPorts();

    //Sets the Port
    void setPort(QString port);

    //Sets the Baudrate
    void setBaudRate(int baudrate);

    //Send a string with current settings
    void send(QString str);

private:
    QString p_port;
    int p_baudrate;
};

#endif // SERIALIO_H
