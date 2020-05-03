#ifndef SETTINGSBUTTON_H
#define SETTINGSBUTTON_H

#include <QDialog>

namespace Ui {
class SettingsButton;
}

class SettingsButton : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsButton(QWidget *parent = nullptr);
    ~SettingsButton();

private:
    Ui::SettingsButton *ui;
};

#endif // SETTINGSBUTTON_H
