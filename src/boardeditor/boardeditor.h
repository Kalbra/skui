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

    void setFile(QString path);

private slots:
    void on_add_clicked();
    void on_delete_clicked();

private:
    QWidget *p_boardeditor;

    QTreeWidget *eventtree = nullptr;
};

#endif // BOARDEDITOR_H
