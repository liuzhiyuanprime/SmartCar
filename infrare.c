#include "infrare.h"

sbit LEFT_T = P3 ^ 3;  //左循迹
sbit RIGHT_T = P3 ^ 2; //右循迹
// 0白1黑
sbit LEFT_A = P3 ^ 4;  //左避障
sbit RIGHT_A = P3 ^ 5; //右避障
// 0有1无

void infrared_track()
{
    if (!LEFT_T && !RIGHT_T)
        Forward();
    else if (!LEFT_T && RIGHT_T)
    {
        Right();
        delay(50);
    }
    else if (LEFT_T && !RIGHT_T)
    {
        Left();
        delay(50);
    }
    else
        Stop();
}
void infrared_avoid()
{
    if (!LEFT_A && !RIGHT_A)
    {
        Back();
        delay(50);
        Circle_Left();
    }
    else if (!LEFT_A && RIGHT_A)
    {
        Circle_Right();
    }
    else if (LEFT_A && !RIGHT_A)
    {
        Circle_Left();
    }
    else
    {
        Forward();
    }
}
void infrared_follow()
{
}