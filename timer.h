#ifndef __TIMER_H__
#define __TIMER_H__
#include <reg52.h>
sbit EN1 = P1 ^ 4; // 高电平左电机使能
sbit EN2 = P1 ^ 5; // 高电平右电机使能
void timer1_init(void);
#endif