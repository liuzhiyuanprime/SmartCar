#include "timer.h"

void timer1_init(void)
{
    TMOD = TMOD | 0x10; //定时器1，工作方式1
    TH1 = 0xff;         //0.25ms定时
    TL1 = 0x1a;
    ET1 = 1; //开定时器1中断
    EA = 1;  //开总中断
    TR1 = 1; //启动计数
}

unsigned int timeOutCounter = 0;
unsigned int pwm = 25;

void timer1_Isr(void) interrupt 3
{
    TH1 = 0xff; //0.25ms定时，重置
    TL1 = 0x1a;
    timeOutCounter++;
    if (timeOutCounter <= pwm) //在pwm范围内，使能
    {
        EN1 = 1;
        EN2 = 1;
    }
    else
    {
        EN1 = 0;
        EN2 = 0;
    }                         //在pwm范围外，禁用
    if (timeOutCounter == 80) //一个pwm周期结束，重新开始计数
    {
        timeOutCounter = 0;
    }
}