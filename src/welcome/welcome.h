#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include <QUrl>
#include <QFileInfo>
#include <QWebEngineView>
#include <QVBoxLayout>

QWidget *WelcomeMessage(){
    QWidget *widget = new QWidget();

    QWebEngineView *webengine = new QWebEngineView(widget);

    QVBoxLayout *layout = new QVBoxLayout(widget);
    layout->setMargin(0);
    layout->addWidget(webengine);




    webengine->load(QUrl::fromLocalFile(QFileInfo("welcome.html").absoluteFilePath()));

    qDebug() << QUrl::fromLocalFile(QFileInfo("./welcome.html").absoluteFilePath());

    return widget;
}



#endif // WELCOME_H
