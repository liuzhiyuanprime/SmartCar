#include <reg52.h>
#include <string.h>
#include "bluetooth.h"
#include "carbasic.h"
#include "timer.h"
#include <stdlib.h>
#include "infrare.h"
#include "csbavoid.h"

#define uchar unsigned char
#define uint unsigned int

sbit DS=P2^2;        
uint temp;  
extern bit command_finish;
extern unsigned char recbuf[20];
extern unsigned char command_team[3][15];
extern unsigned int pwm;
extern unsigned int timersend;
void tmpchange(void);
uint tmp();

main(void)
{
    // 串口初始化
    Serial_Init();
    timer1_init();
    timer0_init();
    sendserial("hello world", 11);

    while (1)
    {
        if (command_finish)
        {
            command_finish = 0;
            Command_Token(recbuf); //解析字符串
        }
        if (!strcmp(command_team[1], "control"))
        {

            switch (command_team[2][0])
            {
            case '1':
                Forward();
                break; //前
            case '2':
                Back();
                break; //后
            case '3':
                Left();
                break; //左
            case '4':
                Right();
                break; //右
            case '5':
                Circle_Left();
                break; //左旋转
            case '6':
                Circle_Right();
                break; // 右旋转
            case '7':
                Hua();
                break; //花样
            case '0':
                Stop();
                break; //停止
            }
        }
        else if (!strcmp(command_team[1], "speed"))
        {
            int n = atoi(command_team[2]);
            pwm = n > 80 ? 80 : n;
        }
        else if (!strcmp(command_team[1], "track"))

            command_team[2][0] == '1' ? infrared_track() : Stop();

        else if (!strcmp(command_team[1], "infrared"))

            command_team[2][0] == '1' ? infrared_avoid() : Stop();

        else if (!strcmp(command_team[1], "ultrasonic"))
            command_team[2][0] == '1' ? csbavoid() : Stop();
        if (timersend >= 8000)
        {
		 uint w ;
          char *ss = "*cmd-getdata-33.5!";
			timersend = 0;
            tmpchange();
           w = tmp();
            ss[12] = w % 1000 / 100;
            ss[13] = w % 100 / 10;
            ss[15] = w % 10;
            sendserial(ss, strlen(ss));
        }
    }
}

void dsreset(void)
{
    uint i;
    DS = 0;
    i = 103;
    while (i > 0)
        i--;
    DS = 1;
    i = 4;
    while (i > 0)
        i--;
}

bit tmpreadbit(void)       //read a bit
{
   uint i;
   bit dat;
   DS=0;i++;          //i++ for delay
   DS=1;i++;i++;
   dat=DS;
   i=8;while(i>0)i--;
   return (dat);
}


uchar tmpread(void)
{
    uchar i, j, dat;
    dat = 0;
    for (i = 1; i <= 8; i++)
    {
        j = tmpreadbit();
        dat = (j << 7) | (dat >> 1);
    }
    return (dat);
}

void tmpwritebyte(uchar dat)
{
    uint i;
    uchar j;
    bit testb;
    for (j = 1; j <= 8; j++)
    {
        testb = dat & 0x01;
        dat = dat >> 1;
        if (testb)
        {
            DS = 0;
            i++;
            i++;
            DS = 1;
            i = 8;
            while (i > 0)
                i--;
        }
        else
        {
            DS = 0;
            i = 8;
            while (i > 0)
                i--;
            DS = 1;
            i++;
            i++;
        }
    }
}

void tmpchange(void)
{
    dsreset();
    delay(1);
    tmpwritebyte(0xcc);
    tmpwritebyte(0x44);
}

uint tmp()
{
    float tt;
    uchar a, b;
    dsreset();
    delay(1);
    tmpwritebyte(0xcc);
    tmpwritebyte(0xbe);
    a = tmpread();
    b = tmpread();
    temp = b;
    temp <<= 8;
    temp = temp | a;
    tt = temp * 0.0625;
    temp = tt * 10 + 0.5;
    return temp;
}