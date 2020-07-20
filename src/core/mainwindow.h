#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "board.h"
#include "../toolbar/toolbar.h"
#include "../dock/DockManager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //Trigger the Boardeditor to make a new board
    void on_new_triggered();

    //Load a file by user filedialog
    void on_open_triggered();

    //Reloads the current board
    void on_reload_triggered();

    //Editmode for the current board
    void on_boardeditor_triggered();

    //On resize, the board will be updateing
    void resizeEvent(QResizeEvent*);

private:
    Toolbar *p_toolbar;

    Ui::MainWindow *ui;

    ads::CDockManager* m_DockManager;

};
#endif // MAINWINDOW_H
