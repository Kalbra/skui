#ifndef SERIALGUI_H
#define SERIALGUI_H

#include <QMainWindow>
#include <vector>

extern int currentbutton;


QT_BEGIN_NAMESPACE
namespace Ui { class Serialgui; }
QT_END_NAMESPACE


struct ButtonElement{
    int mode;
    QString send;
};

extern std::vector <ButtonElement> buttons;

class Serialgui : public QMainWindow
{
    Q_OBJECT

public:
    Serialgui(QWidget *parent = nullptr);
    ~Serialgui();

private slots:
    void on_pushButton_clicked();

    void on_add_clicked();

private:
    Ui::Serialgui *ui;
};
#endif // SERIALGUI_H
