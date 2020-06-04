#ifndef BOARDEDITOR_H
#define BOARDEDITOR_H

#include <QDialog>

namespace Ui {
class Boardeditor;
}

class Boardeditor : public QDialog
{
    Q_OBJECT

public:
    explicit Boardeditor(QWidget *parent = nullptr);
    ~Boardeditor();

private:
    Ui::Boardeditor *ui;
};

#endif // BOARDEDITOR_H
