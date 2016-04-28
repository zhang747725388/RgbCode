/*--- HEADER FILE DESCRIPTOR --------------------------------------------------
Project : Realtime Micro Library
File    : Bsp.h
Author  : automatic.dai
E-mail  : automatic.dai@gmail.com
Data    : 2016/03/26
Version : V1.0(alpha)
Note    : 
-----------------------------------------------------------------------------*/
#ifndef __MODEL_H_
#define __MODEL_H_
/*--- Header Includes -------------------------------------------------------*/
 
 

 /*--- 第0个DA引脚输出的值 -------------------------------------------------------*/


/*--- PCA引脚输出的PWM值 -------------------------------------------------------*/
typedef enum //
{
  PWMValue1=241,	   // 周期是113.72us 高电平周期是 7us
  PWMValue2=199,	   // 周期是113.72us 高电平周期是 25us
  PWMValue3=145,	   // 周期是113.72us 高电平周期是 49us
} PCAPWM;
/*--- PCA引脚输出的PWM值 -------------------------------------------------------*/
extern   u8 DaFlagSwith;
extern  void	ModeOFF();
extern void OpenPower() ;
extern void ClosePower() ;
extern u8 modelflag;
 extern void SetDaModeValue(u8 ModelFlag);
#endif
