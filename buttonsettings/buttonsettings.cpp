#include "buttonsettings.h"
#include "ui_buttonsettings.h"

ButtonSettings::ButtonSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ButtonSettings)
{
    ui->setupUi(this);
}

ButtonSettings::~ButtonSettings()
{
    delete ui;
}
