#include "servocontrolfrom.h"
#include "ui_servocontrolfrom.h"
#include <QDebug>

ServoControlFrom::ServoControlFrom(QSerialPort* _serial, char _id, QWidget* parent) :
    QWidget(parent), ui(new Ui::ServoControlFrom),
    serial(_serial), id(_id)
{
    ui->setupUi(this);

    servo = new Servo(serial, id);

    connect(this,&ServoControlFrom::degreeChanged,this,[&](){
        servo->rotate(degree);
        ui->spinBox->setValue(degree);
    });

    QString title=QString::fromLocal8Bit("舵机")+QString::number(id+1)+QString::fromLocal8Bit("号");
    ui->groupBox->setTitle(title);
}

ServoControlFrom::~ServoControlFrom()
{
    delete ui;
}

int ServoControlFrom::getDegree() const
{
    return degree;
}

void ServoControlFrom::setDegree(int newDegree)
{
    if (degree == newDegree)
        return;
    degree = newDegree;
    emit degreeChanged();
}

void ServoControlFrom::on_dial_sliderMoved(int position)
{
    qDebug()<<position;

    setDegree(position);
}


void ServoControlFrom::on_spinBox_valueChanged(int arg1)
{
    setDegree(arg1);
}

