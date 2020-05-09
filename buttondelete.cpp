#include "buttondelete.h"
#include "ui_buttondelete.h"
#include "serialgui.h"
#include <vector>

bool deleteall = false;

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

void buttondelete::on_enter_clicked()
{
    if(!deleteall){
        for(int i = 0; i < buttons.size(); i++){
            if(buttons[i].name == ui->input->text()){
                buttons.erase(buttons.begin() + i);
            }
        }
    }
    else {
        buttons.clear();
    }
    close();
}

void buttondelete::on_deleteall_stateChanged(int arg1)
{
    if(arg1 == 2){
        deleteall = true;
        ui->input->setEnabled(false);
    }
    else {
        deleteall = false;
    }
}
