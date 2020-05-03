#ifndef SERIALGUI_H
#define SERIALGUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Serialgui; }
QT_END_NAMESPACE

class Serialgui : public QMainWindow
{
    Q_OBJECT

public:
    Serialgui(QWidget *parent = nullptr);
    ~Serialgui();

private:
    Ui::Serialgui *ui;
};
#endif // SERIALGUI_H
