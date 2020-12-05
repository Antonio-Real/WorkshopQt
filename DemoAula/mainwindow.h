#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QLabel>
#include "serialdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    // Statusbar
    void showStatus(QString status);

    // Slots botões
    void connectSerial();
    void disconnectSerial();
    void configureSerial();
    void consolePage();
    void displayPage();

    // Slots de porta serie
    void receiveData();
    void sendData();

    void saveFile();


private:
    Ui::MainWindow *ui;

    QLabel m_status;
    SerialDialog m_dialog;
    QSerialPort m_serial;
};
#endif // MAINWINDOW_H
