#ifndef SERIALIO_H
#define SERIALIO_H
#include <QString>
#include <QtSerialPort/QSerialPortInfo>

class Serialio
{
public:
    Serialio(QString port, int baudrate);

    QList<QSerialPortInfo> getPorts();

    void setPort(QString port);
    void setBaudRate(int baudrate);

    void send(QString str);

private:
    QString p_port;
    int p_baudrate;
};

#endif // SERIALIO_H
