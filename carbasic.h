#ifndef __CARBASIC_H__
#define __CARBASIC_H__
#include <reg52.h>
//定义6个小车驱动模块IO口，例如
// sbit ENL=P1^4; 代表左电机使能端：
// 高电平使能
sbit IN1 = P1 ^ 2; // 高电平1 左电机后退（反转）
sbit IN2 = P1 ^ 3; // 高电平1左电机前进（正转）
sbit IN3 = P1 ^ 6; // 高电平1 右电机前进（正转
sbit IN4 = P1 ^ 7; // 高电平1右电机后退（反转）
sbit EN1 = P1 ^ 4; // 高电平左电机使能
sbit EN2 = P1 ^ 5; // 高电平右电机使能
// 电机函数声明
// 前进，后退，左转，右转，停止，
// 左旋，右旋
void Forward(void);
void Back(void);
void Left(void);
void Right(void);
void Circle_Left(void);
void Circle_Right(void);
void Stop(void);
#endif