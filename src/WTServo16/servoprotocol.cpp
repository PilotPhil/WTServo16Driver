#include "servoprotocol.h"

ServoProtocol::ServoProtocol(QObject* parent)
    : ServoProtocolBase{parent}
{

}

QByteArray ServoProtocol::setServoSpeed(char id, int speed)
{
    int tem = speed / 9;

    QByteArray cmd(5, 0x00);
    cmd[0] = 0xFF;
    cmd[1] = 0x01;
    cmd[2] = id;
    cmd[3] = tem & 0xFF;
    cmd[4] = tem >> 8;
    return cmd;
}

QByteArray ServoProtocol::setServoDegree(char id, int degree)
{
    int freq = map(degree, 0, 180, 500, 2500);
    char L = freq & 0xFF;
    char H = freq >> 8;

    QByteArray cmd(5, 0x00);
    cmd[0] = 0xFF;
    cmd[1] = 0x02;
    cmd[2] = id;
    cmd[3] = L;
    cmd[4] = H;
    return cmd;
}

QByteArray ServoProtocol::stopRestart(char id, ServoState state)
{
    QByteArray cmd(5, 0x00);
    cmd[0] = 0xFF;
    cmd[1] = 0x02;
    cmd[2] = id;
    cmd[3] = state & 0xFF;
    cmd[4] = state >> 8;
    return cmd;
}

float ServoProtocol::map(float val, float I_Min, float I_Max, float O_Min, float O_Max)
{
    return (((val - I_Min) * ((O_Max - O_Min) / (I_Max - I_Min))) + O_Min);
}
