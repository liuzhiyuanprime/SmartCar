#include <reg52.h>
#include <string.h>
#include "bluetooth.h"
#include "carbasic.h"
#include "timer.h"
#include <stdlib.h>
#include "infrare.h"
#include "csbavoid.h"

extern bit command_finish;
extern unsigned char recbuf[20];
extern unsigned char command_team[3][15];
extern unsigned int pwm;

main(void)
{
    // 串口初始化
    Serial_Init();
    timer1_init();
    timer0_init();
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
        {
            command_team[2][0] == '1' ? infrared_track() : Stop();
        }
        else if (!strcmp(command_team[1], "infrared"))
        {
            command_team[2][0] == '1' ? infrared_avoid() : Stop();
        }
        else if (!strcmp(command_team[1], "ultrasonic"))
        {
            command_team[2][0] == '1' ? csbavoid() : Stop();
        }
    }
}