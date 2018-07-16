#include "carbasic.h"

void Forward(void)
{
    EN1 = 1;
    EN2 = 1; //电机使能
    IN1 = 0;
    IN2 = 1; //左电机的正转
    IN3 = 1;
    IN4 = 0; //右电机的正转
}
