#include "serialgui.h"
#include "./ui_serialgui.h"

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

