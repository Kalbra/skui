#include "buttondelete.h"
#include "ui_buttondelete.h"
#include "serialgui.h"
#include <vector>

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
    for(int i = 0; i < buttons.size(); i++){
        if(buttons[i].name == ui->input->text()){
            buttons.erase(buttons.begin() + i);
        }
    }
    close();
}
