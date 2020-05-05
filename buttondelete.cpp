#include "buttondelete.h"
#include "ui_buttondelete.h"

buttondelete::buttondelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buttondelete)
{
    ui->setupUi(this);
}

buttondelete::~buttondelete()
{
    delete ui;
}
