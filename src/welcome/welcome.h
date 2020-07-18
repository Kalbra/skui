#ifndef WELCOME_H
#define WELCOME_H

#include <QObject>
#include <QWidget>

class Welcome : public QObject
{
    Q_OBJECT
public:
    explicit Welcome(QObject *parent = nullptr);

    QWidget *engine();

private slots:
    void openlink(const QUrl &);

};

#endif // WELCOME_H
