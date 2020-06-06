#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

#include "../../boardelements/boardelements.h"

namespace Ui {
class Adddialog;
}

class Adddialog : public QDialog
{
    Q_OBJECT

public:
    Adddialog(Boardelement *boardelement = nullptr);
    ~Adddialog();

private slots:
    void on_eventtypecombobox_currentIndexChanged(int index);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Adddialog *ui;

    Boardelement *p_boardelement;

};

#endif // ADDDIALOG_H
