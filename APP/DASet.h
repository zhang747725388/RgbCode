#ifndef __DASET_H_
#define __DASET_H_
#include "rsystem.h"
 /*--- 后三个DA引脚输出的值 -------------------------------------------------------*/
typedef enum //
{
  ZeroDA1=29,
  Minus_TwoDA1  =19,	   // -2V
  Zero_FiveDA1  =31,	   //0.5V
  Four_NineDA1   =52,	   // 4.9
  Five_OneDA1   =53,		 //5.1V
  Eight_FiveDA1   =70,		 //8.5V
  TenDA1   =77,	//10V
  ElevenDA1   =82	//11V
} DA123;
 /*--- 后三个DA引脚输出的值 -------------------------------------------------------*/

 /*--- 第0个DA引脚输出的值 -------------------------------------------------------*/
typedef enum //
{
  ThreeDA0=70,	   // 3V 70
  FiveDA0=85 ,
  ZeroDA0=45
} DA0;
 
extern u8 DaswitchFlags;
extern u8 SwitchDavalue(u8 flags,u8 modeflag);
#endif
