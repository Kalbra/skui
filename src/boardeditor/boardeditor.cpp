#include "boardeditor.h"
#include "dialog/adddialog.h"
#include "../boardelements/boardelements.h"

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QTreeWidget>

Boardeditor::Boardeditor(){
    p_boardeditor = new QWidget();

    QGridLayout *gridlayout = new QGridLayout;

    QPushButton *add       = new QPushButton("Add");
    QPushButton *delete_   = new QPushButton("Delete");

    connect(add, SIGNAL(clicked()), this, SLOT(on_add_clicked()));


    eventtree = new QTreeWidget();

    gridlayout->addWidget(add,       0, 0, 1, 1);
    gridlayout->addWidget(delete_,   0, 1, 1, 1);
    gridlayout->addWidget(eventtree, 1, 0, 2, 2);

    p_boardeditor->setLayout(gridlayout);

    p_boardeditor->show();
}

void Boardeditor::update(){
    //qDeleteAll(eventtree->children());

    for(int i = 0; i < boardelements.size(); i++){
        Boardelement boardelement = boardelements[i];

        QTreeWidgetItem *type = new QTreeWidgetItem();
        type->setText(0, boardelement.type);

        QTreeWidgetItem *action = new QTreeWidgetItem();
        action->setText(0, boardelement.action);
        action->setFlags(action->flags() | Qt::ItemIsEditable);

        QTreeWidgetItem *name = new QTreeWidgetItem();
        name->setText(0, boardelement.name);
        name->setFlags(name->flags() | Qt::ItemIsEditable);

        type->addChild(action);
        type->addChild(name);

        eventtree->addTopLevelItem(type);
    }
}

void Boardeditor::on_add_clicked(){
    Boardelement *boardelement = new Boardelement();
    Adddialog adddialog(boardelement);
    adddialog.setModal(true);
    adddialog.exec();

    if(boardelement != nullptr){
        boardelements.push_back(*boardelement);
        update();
    }
}

void Boardeditor::on_delete_clicked(){

}

QWidget *Boardeditor::getBoardeditor(){
    return p_boardeditor;
}
