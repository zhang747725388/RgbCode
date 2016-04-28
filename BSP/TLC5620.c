/*
  
 *	文件名:		tlc5620.c
 *	文件描述:	DA转换芯片TLC5620驱动文件
 *			
 *	当前版本:	1.0
 *	作者:	 
 *	完成日期: 	 3.27
 *	
*/
#include "rsystem.h"
/**************************************
说明:	TLC5620初始化
**************************************/
unsigned char DadataSet[]={0,0,0,0};
void TLC5620_Init(void)
{
	TLC5620_CLK = 1;
	TLC5620_DATA = 0;
	TLC5620_LOAD = 0;
	TLC5620_LDAC = 0;
}

/**************************************
说明:	输出单个通道的电压
chl:	通道号, 0--3
dat:	通道数据, 0--255
**************************************/
void TLC5620_SetOutput(unsigned char chl, unsigned char dat)
{
	unsigned char i;

	/* 四个通道，只有低两位有效 */
	chl &= 0x03;
	/* 左移一位，加上RNG位 */
	chl <<= 1;
	chl |= RNG;
	/* 将数据移到高3位 */
	chl <<= 5;

	for(i=3; i>0; i--)
	{
		/* 从高位到低位依次移出数据 */
		TLC5620_DATA = (bit)(chl&0x80);
		/* 等待数据稳定 */
		TLC5620_CLK = 1;
		chl <<= 1;
		/* 下降沿将数据锁存 */
		TLC5620_CLK = 0;
	}
	for(i=8; i>0; i--)
	{
		/* 从高位到低位依次移出数据 */
		TLC5620_DATA = (bit)(dat&0x80);
		/* 等待数据稳定 */
		TLC5620_CLK = 1;
		dat <<= 1;
		/* 下降沿将数据锁存 */
		TLC5620_CLK = 0;
	}
	/* LOAD下降沿将数据锁入寄存器 */
	TLC5620_LOAD = 0;
	_nop_();
	_nop_();
	TLC5620_LOAD = 1;
	_nop_();
	_nop_();
	/* LDAC下降沿将更新输出电压值 */
	TLC5620_LDAC = 0;
	_nop_();
	_nop_();
	TLC5620_LDAC = 1;
}

 void SetMainDaValue1(u8 flagtemp){



}
