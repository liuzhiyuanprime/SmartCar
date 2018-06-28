#include "bluetooth.h"

bit command_finish; //整条接收完
unsigned char recbuf[20] = {0};
unsigned char command_team[3][15] = {0};

//串口初始化
void Serial_Init(void)
{
    SCON = 0x50;
    TH2 = RCAP2H = (65536 - 36) / 256;
    TL2 = RCAP2L = (65536 - 36) % 256;
    T2CON = 0x34;
    PS = 1;
    EA = 1;
    ES = 1;
}
//服务函数
void Serial_Isr(void) interrupt 4
{
    static unsigned char rcnt = 0;
    unsigned char tmp;
    if (RI)
    {
        RI = 0;
        tmp = SBUF;
        if (tmp == '*' && !rcnt)
        {
            recbuf[rcnt++] = tmp;
            SBUF = tmp;
        }
        else if (rcnt)
        {
            recbuf[rcnt++] = tmp;
            SBUF = tmp;
            if (tmp == '!')
            {
                rcnt = 0;
                command_finish = 1;
            }
        }
    }
    else
    {
        TI = 0;
    }
}
//
void Command_Token(const unsigned char *bcomm)
{
    int x = 0, y = 0, i;
    for (i = 0; bcomm[i] != '!'; i++)
    {
        if (bcomm[i] == '-')
        {
            command_team[x][y++] = '\0';
            x++;
            y = 0;
            continue;
        }
        command_team[x][y++] = bcomm[i];
    }
}
void sendserial(char *s, int n)
{
}