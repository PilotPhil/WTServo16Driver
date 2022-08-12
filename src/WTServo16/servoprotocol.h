#ifndef SERVOPROTOCOL_H
#define SERVOPROTOCOL_H

#include "servoprotocolbase.h"

class ServoProtocol : public ServoProtocolBase
{
public:
    explicit ServoProtocol(QObject *parent = nullptr);

    QByteArray setServoSpeed(char id, int speed) override;
    QByteArray setServoDegree(char id, int degree) override;
    QByteArray stopRestart(char id, ServoState state) override;

private:
    float map(float val, float I_Min, float I_Max, float O_Min, float O_Max);
};

#endif // SERVOPROTOCOL_H
