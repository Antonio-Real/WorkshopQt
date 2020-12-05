#include "serialdialog.h"
#include "ui_serialdialog.h"
#include <QSerialPortInfo>

SerialDialog::SerialDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialDialog)
{
    ui->setupUi(this);

    // Inicializar combo boxes
    fillComboBoxes();

    //Conexões de botões
    connect(ui->btn_refresh, &QPushButton::clicked, this, &SerialDialog::refreshPorts);
    connect(ui->btn_apply, &QPushButton::clicked, this, &SerialDialog::hide);
    connect(ui->btn_apply, &QPushButton::clicked, this, &SerialDialog::saveValues);
}

SerialDialog::~SerialDialog()
{
    delete ui;
}


void SerialDialog::fillComboBoxes()
{
    QList<QSerialPortInfo> list = QSerialPortInfo::availablePorts();

    for(int i = 0; i < list.size(); i++) {
        ui->cbox_name->addItem(list.at(i).portName());
    }

    ui->cbox_baudRate->addItem("115200", QSerialPort::Baud115200);
    ui->cbox_baudRate->addItem("57600", QSerialPort::Baud57600);
    ui->cbox_baudRate->addItem("19200", QSerialPort::Baud19200);
    ui->cbox_baudRate->addItem("9600", QSerialPort::Baud9600);

    ui->cbox_parity->addItem("None", QSerialPort::NoParity);
    ui->cbox_parity->addItem("Even", QSerialPort::EvenParity);
    ui->cbox_parity->addItem("Odd", QSerialPort::OddParity);
    ui->cbox_parity->addItem("Mark", QSerialPort::MarkParity);
    ui->cbox_parity->addItem("Space", QSerialPort::SpaceParity);

    ui->cbox_stopBits->addItem("1", QSerialPort::OneStop);
    ui->cbox_stopBits->addItem("1.5", QSerialPort::OneAndHalfStop);
    ui->cbox_stopBits->addItem("2", QSerialPort::TwoStop);

    ui->cbox_dataBits->addItem("8", QSerialPort::Data8);
    ui->cbox_dataBits->addItem("7", QSerialPort::Data7);
    ui->cbox_dataBits->addItem("6", QSerialPort::Data6);
    ui->cbox_dataBits->addItem("5", QSerialPort::Data5);
}

void SerialDialog::refreshPorts()
{
    // Limpar combobox antes de atualizar
    ui->cbox_name->clear();
    // Retorna portas série dos sistema
    QList<QSerialPortInfo> list = QSerialPortInfo::availablePorts();

    for(int i = 0; i < list.size(); i++) {
        ui->cbox_name->addItem(list.at(i).portName());
    }
}

void SerialDialog::saveValues()
{
    m_settings.name = ui->cbox_name->currentText();
    m_settings.baudrate = static_cast<QSerialPort::BaudRate>(ui->cbox_baudRate->currentData().toInt());
    m_settings.parity = static_cast<QSerialPort::Parity>(ui->cbox_parity->currentData().toInt());
    m_settings.stopBits = static_cast<QSerialPort::StopBits>(ui->cbox_stopBits->currentData().toInt());
    m_settings.dataBits = static_cast<QSerialPort::DataBits>(ui->cbox_dataBits->currentData().toInt());
}

SerialDialog::Settings SerialDialog::settings() const
{
    return m_settings;
}
