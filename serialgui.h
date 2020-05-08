#ifndef SERIALGUI_H
#define SERIALGUI_H

#include <QMainWindow>
#include <QtCore>
#include <QPushButton>
#include <vector>


QT_BEGIN_NAMESPACE
namespace Ui { class Serialgui; }
QT_END_NAMESPACE


struct ButtonElement{
    int mode;
    QString send;
    QString name;
};


extern std::vector <ButtonElement> buttons;

class Serialgui : public QMainWindow
{
    Q_OBJECT

public:
    Serialgui(QWidget *parent = nullptr);
    ~Serialgui();

    void updateViewengine();

private slots:
    void on_add_clicked();

    void on_delete_2_clicked();

    void on_load_clicked();

    void on_save_clicked();

    void resizeEvent(QResizeEvent* event);

    void GetEvent(int id);

    void on_zoom_valueChanged(int value);


    void on_percent_editingFinished();

private:
    Ui::Serialgui *ui;

    QPushButton *button;
};
#endif // SERIALGUI_H
