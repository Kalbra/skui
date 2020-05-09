#include "buttonsettings.h"
#include "ui_buttonsettings.h"
#include "serialgui.h"
#include <QDebug>

ButtonSettings::ButtonSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ButtonSettings)
{
    ui->setupUi(this);
    ui->mode->addItem("Button");
    ui->mode->addItem("Slider");
    ui->mode->addItem("Dial");
    ui->mode->addItem("Text Input");
}

ButtonSettings::~ButtonSettings()
{
    delete ui;
}

void ButtonSettings::on_mode_currentIndexChanged(const QString &mode)
{
    if(mode == "Button"){
        ui->button->   setVisible(true);
        ui->dial->     setVisible(false);
        ui->slider->   setVisible(false);
        ui->textinput->setVisible(false);
    }
    else if(mode == "Dial"){
        ui->button->   setVisible(false);
        ui->dial->     setVisible(true);
        ui->slider->   setVisible(false);
        ui->textinput->setVisible(false);
    }
    else if(mode == "Slider"){
        ui->button->   setVisible(false);
        ui->dial->     setVisible(false);
        ui->slider->   setVisible(true);
        ui->textinput->setVisible(false);
    }
    else if(mode == "Text Input"){
        ui->button->   setVisible(false);
        ui->dial->     setVisible(false);
        ui->slider->   setVisible(false);
        ui->textinput->setVisible(true);
    }
}

void ButtonSettings::on_enter_clicked()
{
    int mode = ui->mode->currentIndex();

    ButtonElement button;

    button.mode = mode;

    if(mode == 0){
        button.send = ui->button_input->text();
        button.name = ui->button_input2->text();
    }
    else if(mode == 1){

    }
    else if(mode == 2){
        button.from = ui->dial_from->text().toInt();
        button.to   = ui->dial_to  ->text().toInt();
        button.name = ui->dial_input->text();
    }
    else if(mode == 3){

    }

    if(pushback){
        buttons.push_back(button);
    }
    else{
        buttons[currentbutton] = button;
    }

    close();

}
