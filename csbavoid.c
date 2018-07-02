#include "csbavoid.h"

unsigned long s = 0;

void StartModule()
{
    TRIG = 1;
    //10us
    delay(1);
    TRIG = 0;
}

void Timer_Count()
{
    while (!ECHO)
        ;
    TR0 = 1;
    while (ECHO)
        ;
    TR0 = 0;
}

void distance()
{
    unsigned int time = (TH0 << 8) | TL0;
    TL0 = 0;
    TH0 = 0;
    s = time * 12 * (1.0 / 11.0592) * 0.17; // 单位：mm
}

extern unsigned int timercsb;

void csbavoid()
{
    if (timercsb >= 400)
    {
        timercsb = 0;
        //启动超声波
        StartModule();
        Timer_Count();
        distance();
        if (s < 40)
        {
            //开始避障
            Back();
            delay(500);
            Circle_Left();
            delay(500);
        }
        else
        {
            Forward();
        }
    }
}