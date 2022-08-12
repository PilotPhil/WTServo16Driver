#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include "WTServo16/servocontrolfrom.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);
    ~Widget();

private:
    Ui::Widget* ui;
    QSerialPort* serial;

    ServoControlFrom* s1;
    ServoControlFrom* s2;

};
#endif // WIDGET_H
