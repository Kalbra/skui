#include "serialgui.h"
#include "./ui_serialgui.h"
#include "buttonsettings.h"
#include "saveengine.h"
#include "buttondelete.h"
#include "serial.h"
#include "generalsettings.h"
#include <vector>
#include <QtCore>
#include <QSlider>
#include <QJsonDocument>
#include <QValidator>
#include <QFileDialog>
#include <QDial>
#include <QLabel>

std::vector <ButtonElement> buttons;                                  //Setzt buttons

//      VIEWENGINE
int     VIEWENGINE_BUTTON_SCALE = 100;                                //Setzt die Standartgröße der Buttons

Generalsettings settings;

Serial serial;

Serialgui::Serialgui(QWidget *parent)                                 //Qt kram
    : QMainWindow(parent)                                             //Qt kram
    , ui(new Ui::Serialgui)                                           //Qt kram
{
    ui->setupUi(this);                                                //Qt kram
    ui->percent->setValidator( new QIntValidator(0, 200, this));      //Sagt, dass man in percent(Prozentanzeige oben im Menü) nur Zahlen zwischen 0 und 200 schreiben kann

    QTimer *serialportupdatetime = new QTimer(this);
    connect(serialportupdatetime, SIGNAL(timeout()), this, SLOT(updateavailableports()));
    serialportupdatetime->start(1000);

    settings.BAUD_RADE = 9600;
    settings.FILE_PATH = "../serialgui/save.json";

}

Serialgui::~Serialgui()                                               //Qt kram
{
    delete ui;                                                        //Qt kram
}

void Serialgui::on_add_clicked()                                      //Wenn add geclickt, dann wird ein neuer Button in den Array geschrieben
{
    ButtonSettings buttonsettings;                                    //Definiert das Model welches ein neues Fenster öffnet
    buttonsettings.pushback = true;                                   //Sagt, dass Pushback = true, so wird nicht der jetzige Button bearbeitet, sondern es wird ein neuer erstellt
    buttonsettings.setModal(true);                                    //Sagt, dass erst das Form ausgefüllt werden muss und dann erst im MainWindow weitergearbeitet werden kann
    buttonsettings.exec();                                            //Führt Buttonsettings nun aus
    updateViewengine();                                               //Updatet die Viewengine(wird erst ausgeführt, wenn buttonsettings geschlossen ist)
}

void Serialgui::on_delete_2_clicked(){                                //Löscht einen Button anhand des Namen
    buttondelete buttondelete;                                        //Definiert das Model welches ein neues Fenster öffnet
    buttondelete.setModal(true);                                      //Sagt, dass erst das Form ausgefüllt werden muss und dann erst im MainWindow weitergearbeitet werden kann
    buttondelete.exec();                                              //Führt Buttondelete nun aus
    updateViewengine();                                               //Updatet die Viewengine(wird erst ausgeführt, wenn buttonsettings geschlossen ist)
}

void Serialgui::on_load_clicked(){                                    //Lädt aus die Standarddatei
        LoadButtonsfromFile(settings.FILE_PATH);                      //Führt LoadButtonsfromFile aus, dort passiert die eigentliche Magie
        updateViewengine();                                           //Updatet die Viewengine

}

void Serialgui::on_save_clicked(){                                    //Speichert in die Standarddatei

    SaveButtonsToFile(settings.FILE_PATH);                            //Führt SaveButtonsToFile aus, dort passiert die eigentliche Magie
}

void Serialgui::updateViewengine(){                                   //Erstellt bzw. updatet die Viewengine, eigentlich ist sie die Viewengine
    int buttonx = 0;                                                  //Erstellt buttonx dort wird die X position für den Button gespeichert
    int buttony = 0;                                                  //Erstellt buttony dort wird die Y position für den Button gespeichert
    int windowwidth = width();                                        //Speichert die Window breite

    qDeleteAll(ui->engineinsert->children());                         //Cleart das Widget in dem die Buttons plaziert werden


    for(int i = 0; i < buttons.size(); i++){                          //For Schleife um den Array(buttons) in einzelenen Elementen zu haben
        if((windowwidth - buttonx) < VIEWENGINE_BUTTON_SCALE){        //Wenn der Platz nicht für noch einen Button recht
            buttonx = 0;                                              //Setzt buttonx auf 0, also zum linken Displayrand
            buttony = buttony + VIEWENGINE_BUTTON_SCALE;              //Geht eine Y Stufe nach unten
        }

        if(buttons[i].mode == 0){
            QPushButton *button = new QPushButton(ui->engineinsert);      //Erstellt einen neuen Button in engineinsert
            button->setText(buttons[i].name);                             //Setzt den Namen des Button aus dem Array
            button->setGeometry(buttonx, buttony, VIEWENGINE_BUTTON_SCALE, VIEWENGINE_BUTTON_SCALE);  //Setzt die Koordinaten und die größe des Button


            connect(button, &QPushButton::clicked, this, [=]{ GetButtonEvent(i); });  //Connectet den Button mit GetEvent mit dem Argument i also die jetzige Button ID
            button->show();                                               //Bringt den Button aus den Display
        }

        else if(buttons[i].mode == 2){
            QDial *dial = new QDial(ui->engineinsert);
            dial->setGeometry(buttonx, buttony, VIEWENGINE_BUTTON_SCALE, VIEWENGINE_BUTTON_SCALE);  //Setzt die Koordinaten und die größe des Button
            dial->setRange(buttons[i].from, buttons[i].to);

            QLabel *name = new QLabel(dial);
            name->setText(buttons[i].name);


            connect(dial, &QAbstractSlider::sliderMoved, this, [=] {GetDialEvent(dial->value());});
            dial->show();
            name->show();
        }

        buttonx = buttonx + VIEWENGINE_BUTTON_SCALE;                  //Erhöht buttonx um eine Buttongröße
    }
}

void Serialgui::resizeEvent(QResizeEvent* event)                      //Wenn die Windowgröße geändert wird, dann wird die Viewengine upgedatet
{
   QMainWindow::resizeEvent(event);                                   //Definiert das Event
   updateViewengine();                                                //Updatet die Viewengine
}

void Serialgui::GetButtonEvent(int id){
    serial.WriteToSerial(&settings, buttons[id].send);
}

void Serialgui::GetDialEvent(int value){
    serial.WriteToSerial(&settings, QString::number(value));
}

void Serialgui::on_zoom_valueChanged(int value)                       //Wenn die Slidervalue geändert wird(Slider in der Toolbar oben neben dem delete Button)
{
    VIEWENGINE_BUTTON_SCALE = value;                                  //Setzt Buttonscale auf den Wert von value
    ui->percent->setText(QString::number(value)+"%");                 //Zeigt die Buttongröße in percent(Neben dem Slider rechts)
    updateViewengine();                                               //Updatet die Viewengine
}

void Serialgui::on_percent_editingFinished()                          //Wenn ein eingabe von percent(neben dem Slider) fertig ist, damm soll der Slider gesetzt werden und die Buttongröße
{
    int value = ui->percent->text().toInt();                          //Holt die value aus dem percent Textentry
    VIEWENGINE_BUTTON_SCALE = value;                                  //Setz die Buttonscale auf die value
    ui->zoom->setValue(value);                                        //Setzt den Slider an die richtige Position
}

void Serialgui::updateavailableports(){
    QList<QSerialPortInfo> serialinfolist = serial.FindPorts();

    ui->availableports->clear();

    for(int i = 0; i < serialinfolist.count(); i++){
        ui->availableports->addItem(serialinfolist[i].portName());
    }
    if(serialinfolist.count() == 0){
        ui->engineinsert->setEnabled(false);
    }
    else{
        ui->engineinsert->setEnabled(true);
    }
}

void Serialgui::on_availableports_currentIndexChanged(const QString &arg1)
{
    settings.PORT_NAME = arg1;
}

void Serialgui::on_baudrate_valueChanged(int arg1)
{
    settings.BAUD_RADE = arg1;
}

void Serialgui::on_loadotherfile_clicked()
{
    QString fileurl = QFileDialog::getOpenFileName(this, "Open Skui file", "/", "All File (*.*) ;; Skui File (*.skui) ;; Json File (*.json)");
    if(!(fileurl == "")){
        settings.FILE_PATH = fileurl;
        on_load_clicked();

    }
}
