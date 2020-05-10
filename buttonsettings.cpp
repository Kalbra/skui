#include "buttonsettings.h"
#include "ui_buttonsettings.h"
#include "serialgui.h"
#include <QDebug>
#include <QButtonGroup>

QButtonGroup radiocheck;

ButtonSettings::ButtonSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ButtonSettings)
{
    ui->setupUi(this);
    ui->mode->addItem("Button");
    ui->mode->addItem("Slider");
    ui->mode->addItem("Dial");

    radiocheck.addButton(ui->horizontal);
    radiocheck.addButton(ui->vertical);

}

ButtonSettings::~ButtonSettings()
{
    delete ui;
}

void ButtonSettings::on_mode_currentIndexChanged(const QString &mode)
{
    if(mode == "Button"){
        ui->button->    setVisible(true);
        ui->slider->    setVisible(false);
    }
    else if(mode == "Dial"){
        ui->button->    setVisible(false);
        ui->slider->    setVisible(true);
        ui->horizontal->setVisible(false);
        ui->vertical->  setVisible(false);

    }
    else if(mode == "Slider"){
        ui->button->    setVisible(false);
        ui->slider->    setVisible(true);
        ui->horizontal->setVisible(true);
        ui->vertical->  setVisible(true);
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
        button.from = ui->slider_from->text().toInt();
        button.to   = ui->slider_to  ->text().toInt();
        button.name = ui->slider_input->text();
    }

    else if(mode == 2){
        button.from = ui->slider_from->text().toInt();
        button.to   = ui->slider_to  ->text().toInt();
        button.name = ui->slider_input->text();

        qDebug() << radiocheck.checkedButton();
    }

    if(pushback){
        buttons.push_back(button);
    }
    else{
        buttons[currentbutton] = button;
    }

    close();

}
