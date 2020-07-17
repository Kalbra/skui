#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include <QUrl>
#include <QFileInfo>
#include <QWebEngineView>
#include <QVBoxLayout>
#include <QObject>
#include <QMainWindow>

class Welcome : public QObject
{
    Q_OBJECT

public:

    static QWidget *WelcomeMessage(QMainWindow *window);

};




#endif // WELCOME_H
