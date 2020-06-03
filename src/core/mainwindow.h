#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "board.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void LoadBoards();

    void on_new_triggered();
    void on_open_triggered();

    void on_button_triggered();

    void on_slider_triggered();

    void resizeEvent(QResizeEvent*);

private slots:
    void on_boards_tabCloseRequested(int index);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
