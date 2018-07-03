#ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__
#include <reg52.h>
// 串口初始化等函数声明
void Serial_Init(void);
void Command_Token(const unsigned char *bcomm);
void sendserial(char *s,int n);
#endif