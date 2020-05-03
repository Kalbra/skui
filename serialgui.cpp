#include "serialgui.h"
#include "./ui_serialgui.h"
#include "buttonsettings.h"
#include <vector>

int currentbutton = 5;

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

void Serialgui::on_pushButton_clicked()
{
    ButtonSettings buttonsettings;
    buttonsettings.setModal(true);
    buttonsettings.exec();
}

void Serialgui::on_add_clicked()
{
    ButtonSettings buttonsettings;
    buttonsettings.pushback = true;
    buttonsettings.setModal(true);
    buttonsettings.exec();
}
