/*--- HEADER FILE DESCRIPTOR --------------------------------------------------
Project : Realtime Micro Library
File    : Bsp.h
Author  : automatic.dai
E-mail  : automatic.dai@gmail.com
Data    : 2016/03/26
Version : V1.0(alpha)
Note    : 
-----------------------------------------------------------------------------*/
#ifndef __SETCHANNEL_H_
#define __SETCHANNEL_H_
/*--- Header Includes -------------------------------------------------------*/
#include "rsystem.h" 
typedef enum // 
{
  Vcom       =1,
  G_Even     =2,
  Gcom       =3,
  AAcom      =4,
  VGG        =5,
  G_Odd      =6,
  Bcom       =7,
  Rcom       =8 
} ChannelCode;
#define  DistanceDA 16.3 //DA·å·åÖµ
extern u16	pwm0,pwm1,pwm2,pwm3;
extern void SetChannelData(u8 channel,u8 datavalue);
#endif
