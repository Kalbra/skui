#ifndef BOARDEDITOR_H
#define BOARDEDITOR_H
#include <QWidget>
#include <QObject>
#include <QTreeWidget>

#include "../boardelements/boardelements.h"

class Boardeditor : public QObject
{

    Q_OBJECT
public:
    Boardeditor();

    QWidget *getBoardeditor();

    void setFile(QString path){p_path = path;}

    void loadFile();

private slots:
    void on_add_clicked();
    void on_delete_clicked();
    void on_save_clicked();

private:
    QWidget *p_boardeditor;

    QTreeWidget *eventtree = nullptr;

    void addtoTree(Boardelement *boardelement);

    QString p_path;

};

#endif // BOARDEDITOR_H
