/*
  
 *	�ļ���:		tlc5620.c
 *	�ļ�����:	DAת��оƬTLC5620�����ļ�
 *			
 *	��ǰ�汾:	1.0
 *	����:	 
 *	�������: 	 3.27
 *	
*/
#include "rsystem.h"
/**************************************
˵��:	TLC5620��ʼ��
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
˵��:	�������ͨ���ĵ�ѹ
chl:	ͨ����, 0--3
dat:	ͨ������, 0--255
**************************************/
void TLC5620_SetOutput(unsigned char chl, unsigned char dat)
{
	unsigned char i;

	/* �ĸ�ͨ����ֻ�е���λ��Ч */
	chl &= 0x03;
	/* ����һλ������RNGλ */
	chl <<= 1;
	chl |= RNG;
	/* �������Ƶ���3λ */
	chl <<= 5;

	for(i=3; i>0; i--)
	{
		/* �Ӹ�λ����λ�����Ƴ����� */
		TLC5620_DATA = (bit)(chl&0x80);
		/* �ȴ������ȶ� */
		TLC5620_CLK = 1;
		chl <<= 1;
		/* �½��ؽ��������� */
		TLC5620_CLK = 0;
	}
	for(i=8; i>0; i--)
	{
		/* �Ӹ�λ����λ�����Ƴ����� */
		TLC5620_DATA = (bit)(dat&0x80);
		/* �ȴ������ȶ� */
		TLC5620_CLK = 1;
		dat <<= 1;
		/* �½��ؽ��������� */
		TLC5620_CLK = 0;
	}
	/* LOAD�½��ؽ���������Ĵ��� */
	TLC5620_LOAD = 0;
	_nop_();
	_nop_();
	TLC5620_LOAD = 1;
	_nop_();
	_nop_();
	/* LDAC�½��ؽ����������ѹֵ */
	TLC5620_LDAC = 0;
	_nop_();
	_nop_();
	TLC5620_LDAC = 1;
}

 void SetMainDaValue1(u8 flagtemp){



}
