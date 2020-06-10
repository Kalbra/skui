#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QString>

class Toolbar : public QWidget
{
    Q_OBJECT
public:
    Toolbar();

    QWidget* getToolbar();

    QString getPort();
    int     getBaud();

public slots:
    void update();
    void baudrateChanged(int rate);
    void portnameChanged(QString text);

signals:
    void settingsChanged();

private:
    QWidget   *p_toolbar;
    QSpinBox  *p_baudratespinbox;
    QComboBox *p_ports;

    QString p_portname;
    int     p_baudrate = 9600;

};

#endif // TOOLBAR_H
