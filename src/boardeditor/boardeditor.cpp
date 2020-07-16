#include "boardeditor.h"
#include "dialog/adddialog.h"
#include "../boardelements/boardelements.h"
#include "../saveengine/saveengine.h"
#include "../fileio/filedialog.h"

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QTreeWidget>
#include <QDebug>

Boardeditor::Boardeditor(){
    p_boardeditor = new QWidget();


    QGridLayout *gridlayout = new QGridLayout;

    QPushButton *add       = new QPushButton("Add");
    QPushButton *delete_   = new QPushButton("Delete");
    QPushButton *save      = new QPushButton("Save");

    connect(add,     SIGNAL(clicked()), this, SLOT(on_add_clicked()));
    connect(delete_, SIGNAL(clicked()), this, SLOT(on_delete_clicked()));
    connect(save,    SIGNAL(clicked()), this, SLOT(on_save_clicked()));


    eventtree = new QTreeWidget();

    QTreeWidgetItem *treetitle = eventtree->headerItem();
    treetitle->setText(0, "Value");
    treetitle->setText(1, "Type");

    gridlayout->addWidget(add,       0, 0, 1, 1);
    gridlayout->addWidget(delete_,   0, 1, 1, 1);
    gridlayout->addWidget(save,      0, 2, 1, 1);
    gridlayout->addWidget(eventtree, 1, 0, 3, 3);

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
    }
    eventtree->addTopLevelItem(type);
}

void Boardeditor::loadFile(){
    Saveengine saveengine;
    std::vector<Boardelement> boardelements = saveengine.GetFromFile(p_path);

    for(int i = 0; i < boardelements.size(); i++){
        addtoTree(&boardelements[i]);
    }
}

void Boardeditor::saveFile(){
    qDebug() << "save";
}

void Boardeditor::on_add_clicked(){
    Boardelement *boardelement = new Boardelement();
    Adddialog adddialog(boardelement);
    adddialog.setModal(true);
    adddialog.exec();

    if(boardelement != nullptr){
        addtoTree(boardelement);
    }
}

void Boardeditor::on_delete_clicked(){
    delete eventtree->currentItem();
}

void Boardeditor::on_save_clicked(){
    std::vector<Boardelement> boardelements;
   for(int i = 0; i < eventtree->topLevelItemCount(); i++){
        QTreeWidgetItem *item = eventtree->takeTopLevelItem(i);

        Boardelement boardelement;
        boardelement.type = item->text(0);

        qDebug() << item->child(0)->text(0);

        boardelement.action = item->child(0)->text(0);
        boardelement.name = item->child(1)->text(0);

        if(boardelement.type == "slider"){
            boardelement.from = item->child(2)->text(0).toInt();
            boardelement.to   = item->child(3)->text(0).toInt();
        }
        boardelements.push_back(boardelement);
        //eventtree->addTopLevelItem(item);
    }



    Saveengine saveengine;
    saveengine.SaveToFile(FileDialog::SaveFileDialog(p_boardeditor), boardelements);
}

QWidget *Boardeditor::getBoardeditor(){
    return p_boardeditor;
}
