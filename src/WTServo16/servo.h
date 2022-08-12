#ifndef SERVO_H
#define SERVO_H

#include <QObject>
#include <QSerialPort>
#include "servoprotocol.h"

class Servo : public QObject
{
    Q_OBJECT
public:
    explicit Servo(QSerialPort* _serial, char _id, QObject* parent = nullptr);

    /**
     * @brief rotate
     * @param degree
     */
    void rotate(int degree = 90);

    /**
     * @brief setSpeed
     * @param speed
     */
    void setSpeed(int speed);

    /**
     * @brief setState
     * @param ss
     */
    void setState(const ServoState& ss);

    const QByteArray& getCmd() const;
    void setCmd(const QByteArray& newCmd);

signals:
    void cmdChanged();

private:
    /**
     * @brief id
     */
    char id;

    /**
     * @brief serial
     */
    QSerialPort* serial = nullptr;

    /**
     * @brief servoProtocal
     */
    ServoProtocol* servoProtocal = nullptr;

    /**
     * @brief cmd
     */
    QByteArray cmd;
    Q_PROPERTY(QByteArray cmd READ getCmd WRITE setCmd NOTIFY cmdChanged)
};

#endif // SERVO_H
