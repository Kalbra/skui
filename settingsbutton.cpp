#include "settingsbutton.h"
#include "ui_settingsbutton.h"

SettingsButton::SettingsButton(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsButton)
{
    ui->setupUi(this);
}

SettingsButton::~SettingsButton()
{
    delete ui;
}
