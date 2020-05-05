#ifndef SERIAL_H
#define SERIAL_H
#include <QtCore>

class Serial : public QObject
{
    Q_OBJECT

    public slots:
        void GetEvent();


};

#endif // SERIAL_H
