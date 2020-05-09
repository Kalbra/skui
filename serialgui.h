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
    int mode     = 0;
    QString send = "";
    QString name = "";
    int from     = 0;
    int to       = 0;
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

    void GetButtonEvent(int id);

    void GetDialEvent(int value);

    void on_zoom_valueChanged(int value);

    void on_percent_editingFinished();

    void updateavailableports();

    void on_availableports_currentIndexChanged(const QString &arg1);

    void on_baudrate_valueChanged(int arg1);

    void on_loadotherfile_clicked();

private:
    Ui::Serialgui *ui;

    QPushButton *button;
};
#endif // SERIALGUI_H
