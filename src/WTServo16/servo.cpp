#include "servo.h"

Servo::Servo(QSerialPort* _serial, char _id, QObject* parent): QObject{parent}, id(_id), serial(_serial)
{
    servoProtocal = new ServoProtocol(this);

    connect(this, &Servo::cmdChanged, this, [&]()
    {
        if (serial != nullptr && serial->isOpen() == true)
            serial->write(cmd);
    });
}

void Servo::rotate(int degree)
{
    auto cmd = servoProtocal->setServoDegree(id, degree);
    setCmd(cmd);
}

void Servo::setSpeed(int speed)
{
    auto cmd = servoProtocal->setServoSpeed(id, speed);
    setCmd(cmd);
}

void Servo::setState(const ServoState& ss)
{
    auto cmd = servoProtocal->stopRestart(id, ss);
    setCmd(cmd);
}

const QByteArray& Servo::getCmd() const
{
    return cmd;
}

void Servo::setCmd(const QByteArray& newCmd)
{
    if (cmd == newCmd)
        return;
    cmd = newCmd;
    emit cmdChanged();
}
