#include "serialgui.h"
#include "./ui_serialgui.h"
#include "buttonsettings.h"
#include "saveengine.h"
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
}

void Serialgui::on_delete_2_clicked()
{
    for(int i = 0; i < buttons.size(); i++){
        qDebug() << buttons[i].mode;
        qDebug() << buttons[i].send;
    }
}

void Serialgui::on_load_clicked()
{
    LoadButtonsfromFile("../serialgui/save.json");
}

void Serialgui::on_save_clicked()
{
    SaveButtonsToFile("../serialgui/save.json");
}
