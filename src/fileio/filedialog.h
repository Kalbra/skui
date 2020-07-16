#ifndef FILEDIALOG_H
#define FILEDIALOG_H
#include <QString>
#include <QFileDialog>
#include <QMainWindow>

class FileDialog{
public:
    static QString OpenFileDialog(QMainWindow *window){                                                 //Funktion um einen Filedialog zu erzeugen(für Open)
        return QFileDialog::getOpenFileName(window, "Open Skui file", "/", "All File (*.*) ;; Skui File (*.skui) ;; Json File (*.json)");  //Returnt das Ergebnis, welches auch in dieser Zeile erbracht wird
    }

    static QString OpenFileDialog(QWidget *window){
        return QFileDialog::getOpenFileName(window, "Open Skui file", "/", "All File (*.*) ;; Skui File (*.skui) ;; Json File (*.json)");
    }

    static QString SaveFileDialog(QMainWindow *window){                                                 //Funktion um einen Filedialog zu erzeugen(für Save)
        return QFileDialog::getSaveFileName(window, "Open Skui file", "/", "All File (*.*) ;; Skui File (*.skui) ;; Json File (*.json)");  //Returnt das Ergebnis, welches auch in dieser Zeile erbracht wird
    }

    static QString SaveFileDialog(QWidget *window){
        return QFileDialog::getSaveFileName(window, "Open Skui file", "/", "All File (*.*) ;; Skui File (*.skui) ;; Json File (*.json)");  //Returnt das Ergebnis, welches auch in dieser Zeile erbracht wird
    }
};


#endif // FILEDIALOG_H
