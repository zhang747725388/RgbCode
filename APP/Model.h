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
 
 

 /*--- ��0��DA���������ֵ -------------------------------------------------------*/


/*--- PCA���������PWMֵ -------------------------------------------------------*/
typedef enum //
{
  PWMValue1=241,	   // ������113.72us �ߵ�ƽ������ 7us
  PWMValue2=199,	   // ������113.72us �ߵ�ƽ������ 25us
  PWMValue3=145,	   // ������113.72us �ߵ�ƽ������ 49us
} PCAPWM;
/*--- PCA���������PWMֵ -------------------------------------------------------*/
extern   u8 DaFlagSwith;
extern  void	ModeOFF();
extern void OpenPower() ;
extern void ClosePower() ;
extern u8 modelflag;
 extern void SetDaModeValue(u8 ModelFlag);
#endif
