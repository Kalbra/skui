#ifndef BUTTONSETTINGS_H
#define BUTTONSETTINGS_H

#include <QDialog>

namespace Ui {
class ButtonSettings;
}

class ButtonSettings : public QDialog
{
    Q_OBJECT

public:
    explicit ButtonSettings(QWidget *parent = nullptr);
    ~ButtonSettings();

private:
    Ui::ButtonSettings *ui;
};

#endif // BUTTONSETTINGS_H
