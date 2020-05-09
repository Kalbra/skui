#ifndef BUTTONDELETE_H
#define BUTTONDELETE_H

#include <QDialog>

namespace Ui {
class buttondelete;
}

class buttondelete : public QDialog
{
    Q_OBJECT

public:
    explicit buttondelete(QWidget *parent = nullptr);
    ~buttondelete();

private slots:
    void on_enter_clicked();

    void on_deleteall_stateChanged(int arg1);

private:
    Ui::buttondelete *ui;
};

#endif // BUTTONDELETE_H
