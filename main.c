#include <reg52.h>
#include <string.h>
#include "bluetooth.h"
#include "carbasic.h"

extern bit command_finish;
extern unsigned char recbuf[20];
extern unsigned char command_team[3][15];

main(void)
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
					break ;//左
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
                    break; //花样
                case '0':
                    Stop();
                    break; //停止
                }
            }
        }
    }
}