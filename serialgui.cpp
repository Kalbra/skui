#include "serialgui.h"
#include "./ui_serialgui.h"
#include "buttonsettings.h"
#include "saveengine.h"
#include "serial.h"
#include <vector>
#include <QtCore>
#include <QJsonDocument>

std::vector <ButtonElement> buttons;

Serialgui::Serialgui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Serialgui)
{
    ui->setupUi(this);

}

Serialgui::~Serialgui()
{
    delete ui;
}

void Serialgui::on_add_clicked()
{
    ButtonSettings buttonsettings;
    buttonsettings.pushback = true;
    buttonsettings.setModal(true);
    buttonsettings.exec();
    updateViewengine();
}

void Serialgui::on_delete_2_clicked(){
    qDebug() << "something";
    updateViewengine();
}

void Serialgui::on_load_clicked(){

    LoadButtonsfromFile("../serialgui/save.json");
    updateViewengine();
}

void Serialgui::on_save_clicked(){

    SaveButtonsToFile("../serialgui/save.json");
}

void Serialgui::updateViewengine(){
    int buttonx = 0;
    int buttony = 0;
    int windowwidth = width();

    qDeleteAll(ui->engineinsert->children());


    for(int i = 0; i < buttons.size(); i++){
        if((windowwidth - buttonx) < 100){
            buttonx = 0;
            buttony = buttony + 100;
        }

        QPushButton *button = new QPushButton(ui->engineinsert);
        button->setText(buttons[i].name);
        button->setGeometry(buttonx, buttony, 100, 100);



        connect(button, &QPushButton::clicked, this, [=]{ GetEvent(i); });
        button->show();

        buttonx = buttonx + 100;
    }
}

void Serialgui::resizeEvent(QResizeEvent* event)
{
   QMainWindow::resizeEvent(event);
   updateViewengine();
}

void Serialgui::GetEvent(int id){
    qDebug() << buttons[id].send;
}















