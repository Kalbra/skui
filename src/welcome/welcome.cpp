#include "welcome.h"
#include <QWidget>
#include <QUrl>
#include <QFileInfo>
#include <QWebEngineView>
#include <QVBoxLayout>
#include <QObject>
#include <QMainWindow>


QWidget * Welcome::WelcomeMessage(QMainWindow *window){
    QWidget *widget = new QWidget();

    QWebEngineView *webengine = new QWebEngineView(widget);

    webengine->setUrl(QUrl("qrc:/html/welcome.html"));

    connect(webengine, SIGNAL(urlChanged(const QUrl &url)), window, SLOT([]{qDebug() << "lsdfjk";}));


    QVBoxLayout *layout = new QVBoxLayout(widget);
    layout->setMargin(0);
    layout->addWidget(webengine);

    return widget;
}
