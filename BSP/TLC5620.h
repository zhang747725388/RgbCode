/*

*/
#ifndef __TLC5620_H__
#define __TLC5620_H__
#include "rsystem.h"
/* TLC5620串行总线IO口定义 */
sbit    TLC5620_CLK  = P2^5;
sbit	TLC5620_DATA = P2^7;
sbit	TLC5620_LOAD = P3^4;
sbit	TLC5620_LDAC = P2^6;
unsigned char DadataSet[];

/* 当RNG=0时，输出电压范围为 REF--GND 
   当RNG=1时，输出电压范围为 2*REF--GND
*/
#define RNG				(0x01)

#define CHL0			(0x00)
#define CHL1			(0x01)
#define CHL2			(0x02)
#define CHL3			(0x03)


/* 函数接口 */
void TLC5620_Init(void);
/* 输出单个通道的电压 */
void TLC5620_SetOutput(unsigned char chl, unsigned char dat);
/* 同时刻输出四个通道电压 */
//void TLC5620_AllOutput(unsigned char dat[]);
#endif /* __TLC5620_H__ */
