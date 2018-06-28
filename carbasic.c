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
void Back(void)
{
    EN1 = 1;
    EN2 = 1; //电机使能
    IN1 = 1;
    IN2 = 0; //左电机的正转
    IN3 = 0;
    IN4 = 1; //右电机的正转
}
void Left(void)
{
    EN1 = 0;
    EN2 = 0;
    EN1 = 1;
    EN2 = 1; //电机使能
    IN1 = 0;
    IN2 = 0; //左电机的正转
    IN3 = 1;
    IN4 = 0; //右电机的正转
}
void Right(void)
{
    EN1 = 0;
    EN2 = 0;
    EN1 = 1;
    EN2 = 1; //电机使能
    IN1 = 0;
    IN2 = 1; //左电机的正转
    IN3 = 0;
    IN4 = 0; //右电机的正转
}
void Circle_Left(void)
{
    EN1 = 1;
    EN2 = 1; //电机使能
    IN1 = 1;
    IN2 = 0; //左电机的正转
    IN3 = 1;
    IN4 = 0; //右电机的正转
}
void Circle_Right(void)
{
    EN1 = 1;
    EN2 = 1; //电机使能
    IN1 = 0;
    IN2 = 1; //左电机的正转
    IN3 = 0;
    IN4 = 1; //右电机的正转
}
void Hua(void)
{
    Forward();
    delay(2000);
    Circle_Left();
    delay(500);
    Circle_Right();
    delay(200);
    Left();
    delay(1000);
    Right();
    delay(1000);
    Back();
    delay(2000);
    Forward();
    delay(1500);
    Stop();
}
void Stop(void)
{
    EN1 = 0;
    EN2 = 0; //电机使能
    IN1 = 0;
    IN2 = 0; //左电机的正转
    IN3 = 0;
    IN4 = 0; //右电机的正转
}