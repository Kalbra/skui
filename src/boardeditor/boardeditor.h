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

    void update();

private slots:
    void on_add_clicked();

private:
    void on_delete_clicked();

    QWidget *p_boardeditor;

    QTreeWidget *eventtree = nullptr;

    void addtoTree(Boardelement *boardelement);
};

#endif // BOARDEDITOR_H
