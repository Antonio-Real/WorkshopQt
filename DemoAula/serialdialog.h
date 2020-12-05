#ifndef SERIALDIALOG_H
#define SERIALDIALOG_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>

namespace Ui {
class SerialDialog;
}

class SerialDialog : public QDialog
{
    Q_OBJECT

public:

    struct Settings {
        QString name;
        int baudrate;
        QSerialPort::DataBits dataBits;
        QSerialPort::Parity parity;
        QSerialPort::StopBits stopBits;
    };

    explicit SerialDialog(QWidget *parent = nullptr);
    ~SerialDialog();

    Settings settings() const;


private:
    void fillComboBoxes();


private slots:
    void refreshPorts();
    void saveValues();

private:
    Ui::SerialDialog *ui;

    Settings m_settings;
};

#endif // SERIALDIALOG_H
