#ifndef SERVOCONTROLFROM_H
#define SERVOCONTROLFROM_H

#include <QWidget>
#include "servo.h"

namespace Ui {
class ServoControlFrom;
}

class ServoControlFrom : public QWidget
{
    Q_OBJECT
public:
    explicit ServoControlFrom(QSerialPort* _serial, char _id, QWidget* parent = nullptr);
    ~ServoControlFrom();

    int getDegree() const;
    void setDegree(int newDegree);

signals:
    void degreeChanged();

private slots:
    void on_dial_sliderMoved(int position);

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::ServoControlFrom* ui;
    QSerialPort* serial;
    char id;
    Servo* servo;

    int degree;
    Q_PROPERTY(int degree READ getDegree WRITE setDegree NOTIFY degreeChanged)
};

#endif // SERVOCONTROLFROM_H
