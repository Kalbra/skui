#include "adddialog.h"
#include "ui_adddialog.h"
#include "../../boardelements/boardelements.h"

#include <QDebug>

Adddialog::Adddialog(Boardelement* boardelement) :
    QDialog(nullptr),
    ui(new Ui::Adddialog)
{
    ui->setupUi(this);
    p_boardelement = boardelement;

    p_boardelement->type = "button";
    ui->fromtofield->setEnabled(false);
}

Adddialog::~Adddialog()
{
    delete ui;
}

void Adddialog::on_eventtypecombobox_currentIndexChanged(int index){
    qDebug() << index;
    switch (index) {
        case 0:{
            p_boardelement->type = "button";
            ui->fromtofield->setEnabled(false);
            qDebug() << "button";
            break;
        }
        case 1:{
            p_boardelement->type = "slider";
            ui->fromtofield->setEnabled(true);
            break;
        }
    }
}

void Adddialog::on_buttonBox_accepted(){
    p_boardelement->action = ui->actioninput->text();
    p_boardelement->name   = ui->nameinput->text();

    if(p_boardelement->type == "slider"){
        p_boardelement->from = ui->fromspinBox->value();
        p_boardelement->to   = ui->tospinBox->value();
    }
}

void Adddialog::on_buttonBox_rejected(){
    p_boardelement = nullptr;
}
