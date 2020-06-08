#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QComboBox>
#include <QString>

class Toolbar : public QWidget
{
    Q_OBJECT
public:
    Toolbar();

    QWidget* getToolbar();

    QString portname;
    int baudrate;

public slots:
    void update();

private:
    QWidget *p_toolbar;
    QComboBox *p_ports;

};

#endif // TOOLBAR_H
