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

    QTreeWidgetItem *treetitle = eventtree->headerItem();
    treetitle->setText(0, "Value");
    treetitle->setText(1, "Type");

    gridlayout->addWidget(add,       0, 0, 1, 1);
    gridlayout->addWidget(delete_,   0, 1, 1, 1);
    gridlayout->addWidget(eventtree, 1, 0, 2, 2);

    p_boardeditor->setLayout(gridlayout);

    p_boardeditor->show();
}

void Boardeditor::addtoTree(Boardelement *boardelement){
    QTreeWidgetItem *type = new QTreeWidgetItem();
    type->setText(0, boardelement->type);
    type->setText(1, "Event type");

    QTreeWidgetItem *action = new QTreeWidgetItem();
    action->setText(0, boardelement->action);
    action->setText(1, "Action");
    action->setFlags(action->flags() | Qt::ItemIsEditable);

    QTreeWidgetItem *name = new QTreeWidgetItem();
    name->setText(0, boardelement->name);
    name->setText(1, "Name");
    name->setFlags(name->flags() | Qt::ItemIsEditable);

    type->addChild(action);
    type->addChild(name);

    if(boardelement->type == "slider"){
        QTreeWidgetItem *from = new QTreeWidgetItem();
        from->setText(0, QString::number(boardelement->from));
        from->setText(1, "From");
        from->setFlags(from->flags() | Qt::ItemIsEditable);

        QTreeWidgetItem *to   = new QTreeWidgetItem();
        to->setText(0, QString::number(boardelement->to));
        to->setText(1, "To");
        to->setFlags(to->flags() | Qt::ItemIsEditable);

        if(boardelement.type == "slider"){
            QTreeWidgetItem *from = new QTreeWidgetItem();
            from->setText(0, QString::number(boardelement.from));
            from->setFlags(from->flags() | Qt::ItemIsEditable);

            QTreeWidgetItem *to   = new QTreeWidgetItem();
            to->setText(0, QString::number(boardelement.to));
            from->setFlags(to->flags() | Qt::ItemIsEditable);

            type->addChild(from);
            type->addChild(to);
    }

}


void Boardeditor::on_add_clicked(){
    Boardelement *boardelement = new Boardelement();
    Adddialog adddialog(boardelement);
    adddialog.setModal(true);
    adddialog.exec();

    if(boardelement != nullptr){
        QTreeWidgetItem *type = new QTreeWidgetItem();
        type->setText(0, boardelement->type);

        QTreeWidgetItem *action = new QTreeWidgetItem();
        action->setText(0, boardelement->action);
        action->setFlags(action->flags() | Qt::ItemIsEditable);

        QTreeWidgetItem *name = new QTreeWidgetItem();
        name->setText(0, boardelement->name);
        name->setFlags(name->flags() | Qt::ItemIsEditable);

        type->addChild(action);
        type->addChild(name);

        if(boardelement->type == "slider"){
            QTreeWidgetItem *from = new QTreeWidgetItem();
            from->setText(0, QString::number(boardelement->from));
            from->setFlags(from->flags() | Qt::ItemIsEditable);

            QTreeWidgetItem *to   = new QTreeWidgetItem();
            to->setText(0, QString::number(boardelement->to));
            from->setFlags(to->flags() | Qt::ItemIsEditable);

            type->addChild(from);
            type->addChild(to);
        }

        eventtree->addTopLevelItem(type);
    }
}

void Boardeditor::on_delete_clicked(){

}

QWidget *Boardeditor::getBoardeditor(){
    return p_boardeditor;
}
