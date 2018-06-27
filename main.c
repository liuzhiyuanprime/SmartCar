#include <reg52.h>
#include <string.h>
#include "bluetooth.h"

extern bit command_finish;
extern unsigned char recbuf[20];
extern unsigned char command_team[3][15];

sbit LED0 = P1 ^ 0;
sbit LED1 = P1 ^ 1;
sbit LED2 = P1 ^ 2;
sbit LED3 = P1 ^ 3;
sbit LED4 = P1 ^ 4;
sbit LED5 = P1 ^ 5;
sbit LED6 = P1 ^ 6;
sbit LED7 = P1 ^ 7;

main()
{
    // 串口初始化
    Serial_Init();
    while (1)
    {
        if (command_finish)
        {
            command_finish = 0;
            Command_Token(recbuf); //解析字符串
            if (!strcmp(command_team[1], "control"))
            {
                P1 = 0xff;
                switch (command_team[2][0])
                {
                case '1':
                    LED0 = 0;
                    break; //前
                case '2':
                    LED1 = 0;
                    break; //后
                case '3':
                    LED2 = 0;
                    break; //左
                case '4':
                    LED3 = 0;
                    break; //右
                case '5':
                    LED4 = 0;
                    break; //左旋转
                case '6':
                    LED5 = 0;
                    break; // 右旋转
                case '7':
                    LED6 = 0;
                    break; //花样
                case '0':
                    LED7 = 0;
                    break; //停止
                }
            }
        }
    }
}