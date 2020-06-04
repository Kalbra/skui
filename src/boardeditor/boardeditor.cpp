#include "boardeditor.h"
#include "ui_boardeditor.h"

Boardeditor::Boardeditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Boardeditor)
{
    ui->setupUi(this);
}

Boardeditor::~Boardeditor()
{
    delete ui;
}
