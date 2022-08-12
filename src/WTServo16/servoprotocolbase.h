#ifndef SERVOPROTOCOLBASE_H
#define SERVOPROTOCOLBASE_H

#include <QObject>

enum ServoState
{
    restore,//0.恢复运行
    emergencyStop//1.急停
};

class ServoProtocolBase : public QObject
{
    Q_OBJECT
public:
    explicit ServoProtocolBase(QObject* parent = nullptr);

signals:

protected:
    /**
     * @brief setServoSpeed 设置舵机速度
     * @param id
     * @param speed
     */
    virtual QByteArray setServoSpeed(char id, int speed) = 0;

    /**
     * @brief setServoDegree 设置舵机角度
     * @param id
     * @param degree
     */
    virtual QByteArray setServoDegree(char id, int degree) = 0;

    /**
     * @brief stopRestart 停止/恢复
     * @param id
     */
    virtual QByteArray stopRestart(char id, ServoState state) = 0;
};

#endif // SERVOPROTOCOLBASE_H
