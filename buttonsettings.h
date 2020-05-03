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
    bool pushback;
    int currentbutton;

private slots:
    void on_mode_currentIndexChanged(const QString &arg1);

    void on_enter_clicked();

private:
    Ui::ButtonSettings *ui;
};

#endif // BUTTONSETTINGS_H
