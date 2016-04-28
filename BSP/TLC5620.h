/*

*/
#ifndef __TLC5620_H__
#define __TLC5620_H__
#include "rsystem.h"
/* TLC5620��������IO�ڶ��� */
sbit    TLC5620_CLK  = P2^5;
sbit	TLC5620_DATA = P2^7;
sbit	TLC5620_LOAD = P3^4;
sbit	TLC5620_LDAC = P2^6;
unsigned char DadataSet[];

/* ��RNG=0ʱ�������ѹ��ΧΪ REF--GND 
   ��RNG=1ʱ�������ѹ��ΧΪ 2*REF--GND
*/
#define RNG				(0x01)

#define CHL0			(0x00)
#define CHL1			(0x01)
#define CHL2			(0x02)
#define CHL3			(0x03)


/* �����ӿ� */
void TLC5620_Init(void);
/* �������ͨ���ĵ�ѹ */
void TLC5620_SetOutput(unsigned char chl, unsigned char dat);
/* ͬʱ������ĸ�ͨ����ѹ */
//void TLC5620_AllOutput(unsigned char dat[]);
#endif /* __TLC5620_H__ */
