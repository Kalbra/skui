#include "welcome.h"
#include <QWidget>
#include <QWebEngineView>
#include <QUrl>
#include <QVBoxLayout>

Welcome::Welcome(QObject *parent) : QObject(parent){

}

QWidget *Welcome::engine(){
    QWidget *widget = new QWidget();

    QWebEngineView *webengine = new QWebEngineView(widget);

    webengine->setUrl(QUrl("qrc:/html/welcome.html"));

    qDebug() << connect(webengine, SIGNAL(urlChanged(const QUrl &)), this, SLOT(openlink(const QUrl &)));

    QVBoxLayout *layout = new QVBoxLayout(widget);
    layout->setMargin(0);
    layout->addWidget(webengine);

    return widget;
}

void Welcome::openlink(const QUrl &url){
    qDebug() << "!";
    qDebug() << url;
}
