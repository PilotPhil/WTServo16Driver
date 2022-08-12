#include "widget.h"
#include "./ui_widget.h"
#include <QGridLayout>
#include <QHBoxLayout>

Widget::Widget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    serial = new QSerialPort(this);
    serial->setPort(QSerialPortInfo("COM7"));
    serial->setBaudRate(9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->open(QIODevice::WriteOnly);

//    QHBoxLayout* gl1 = new QHBoxLayout;
    s1 = new ServoControlFrom(serial, 0x00, nullptr);
    s2 = new ServoControlFrom(serial, 0x01, nullptr);
//    gl1->addWidget(s1);
//    gl1->addWidget(s2);
//    this->setLayout(gl1);

    ui->gridLayout->addWidget(s1);
    ui->gridLayout->addWidget(s2);
}


Widget::~Widget()
{
    serial->close();

    delete ui;
}
