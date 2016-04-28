#ifndef __KEY_H_
#define __KEY_H_
#include "rsystem.h"
typedef enum _KeyStaEnum{
 	NoPut     = 0,				// 默认
	Short 	  = 1,				// 短按
	Long      = 2 				// 长按
}KeyStaEnum;


 

sbit KEY0_STATUS =  P3^3;   
sbit KEY1_STATUS =  P3^2;        
sbit KEY2_STATUS =  P2^3;     
sbit KEY3_STATUS =  P2^2;      
 

#define RESET 0
#define KEY_SERIES_FLAG    100       //按键连发开始所需时间长度
#define KEY_SERIES_DELAY    50       //按键连发的时间间隔长度

//按键属性
#define KEY_DOWN        0xA0
#define KEY_LONG        0xB0
#define KEY_LIAN        0xC0
#define KEY_UP          0xD0
#define KEY_SHORT       0xE0

 
#define KEY0_DOWN        0xA1
#define KEY0_LONG        0xB1
#define KEY0_LIAN        0xC1
#define KEY0_UP          0xD1

#define KEY1_DOWN        0xA2
#define KEY1_LONG        0xB2
#define KEY1_LIAN        0xC2
#define KEY1_UP          0xD2

#define KEY2_DOWN        0xA3
#define KEY2_LONG        0xB3
#define KEY2_LIAN        0xC3
#define KEY2_UP          0xD3

#define KEY3_DOWN        0xA4
#define KEY3_LONG        0xB4
#define KEY3_LIAN        0xC4
#define KEY3_UP          0xD4

 




#define NO_KEY          0x00

#define KEY_DOWN1       0X01
#define KEY_DOWN2       0X02
#define KEY_DOWN3       0X03
#define KEY_DOWN4       0X04
 


#define KEY0_PRESS      (KEY_DOWN|KEY0_DOWN)
#define KEY1_PRESS      (KEY_DOWN|KEY1_DOWN)
#define KEY2_PRESS      (KEY_DOWN|KEY2_DOWN)
#define KEY3_PRESS      (KEY_DOWN|KEY3_DOWN)
 
uchar Key_Scan(void);
void KeyAction(u8 flag);
void MainKeytask(void);

#endif
