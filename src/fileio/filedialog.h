#ifndef FILEDIALOG_H
#define FILEDIALOG_H
#include <QString>
#include <QFileDialog>
#include <QMainWindow>

QString OpenFileDialog(QMainWindow *window){                          //Funktion um einen Filedialog zu erzeugen
    return QFileDialog::getOpenFileName(window, "Open Skui file", "/", "All File (*.*) ;; Skui File (*.skui) ;; Json File (*.json)");  //Returnt das Ergebnis, welches auch in dieser Zeile erbracht wird
}

#endif // FILEDIALOG_H
