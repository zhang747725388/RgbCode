/*************	����˵��	**************
 

******************************************/



#include "rsystem.h"
INT32U	r_tickcnt;	 
u8 uiflag=0;
/********************* Timer0�жϺ���************************/
void timer0_int (void) interrupt TIMER0_VECTOR
{
   	static INT32U tickcnt = 0;
   	  	static INT32U Autocnt = 0;
	if ( ++tickcnt >= RML_SYSTICK_TIME )
	{
	  tickcnt = 0;
	   Autocnt++;
	  r_tickcnt++;
//	  	PrintString1("Init UART1...\r\n");	//SUART1����һ���ַ���
	
	   	if(r_tickcnt>6553){
	   
                          r_tickcnt=0;
                  } 
 	}
	   if(OpenFlag==1){
	   		 SwitchModel();
	      switch(AutoFlag){
		  case  0:  
		  	break;
		   case  1:
			  	if(Autocnt>100){
	   				   modelflag++;
					   if(modelflag>8){
					   
					   modelflag=0; 
					   }
                          Autocnt=0;
                  } 
		  	break;
		  }
	   	
	   }
	

		 
}

/********************* Timer1�жϺ���************************/
void timer1_int (void) interrupt TIMER1_VECTOR
{
 
	 
// 	  DaswitchFlags=!DaswitchFlags;
//	  if(SwitchDavalue(DaswitchFlags))
//	{
//		TH1 = (u8)(PWM_high1 >> 8);	//���������͵�ƽ����װ�ظߵ�ƽʱ�䡣
//		TL1 = (u8)PWM_high1;
//   
//    
//	}
// 
//	else 	{
//		TH1 =  (u8)(PWM_low1 >> 8);	//���������ߵ�ƽ����װ�ص͵�ƽʱ�䡣
//		TL1 = (u8)PWM_low1;
//     	 uiflag++;
//	}
//     switch(uiflag){
//	  case 0:
//		    TLC5620_SetOutput(1, 19)  ;	break;
//	  case 1:
//		    TLC5620_SetOutput(1, 19)  ;	break;
//      case 2:
// 		    TLC5620_SetOutput(1, 19)  ;	break;
//	  case 3:
//		    TLC5620_SetOutput(1, 19)  ;	break;
//	  case 4:
//		    TLC5620_SetOutput(1, 19)  ;		break;
//      case 5:
//		    TLC5620_SetOutput(1, 19)  ;		break;
//	  case 6:
//		    TLC5620_SetOutput(1, 19)  ;		break;
//	  case 7:
//		    TLC5620_SetOutput(1, 19)  ;   	break;	 
//      case 8:
//		    TLC5620_SetOutput(1, 82)  ;		break;
//	  
//      case 9:
//		    TLC5620_SetOutput(1, 82)  ;	 	break;
//	  case 10:
//		    TLC5620_SetOutput(1, 82)  ;		break;
//      case 11:
//		    TLC5620_SetOutput(1, 82)  ;	 	break;
//	 
//	   case 12:
//		    TLC5620_SetOutput(1, 82)  ;	 	break;
//	 
//	   case 13:
//		    TLC5620_SetOutput(1, 82)  ;	 	break;
//	 
//	   case 14:
//		    TLC5620_SetOutput(1, 82)  ;	 	break;
//	 
//	   case 15:
//		    TLC5620_SetOutput(1, 82)  ;	uiflag=0; 	break;
//	  
//	 }

}

 
/************************ ��ʱ������ ****************************/
void	Timer_config(void)
{
	
	TIM_InitTypeDef		TIM_InitStructure1;					//�ṹ����
	TIM_InitTypeDef		TIM_InitStructure;					//�ṹ����
	TIM_InitStructure.TIM_Mode      = TIM_16Bit;	//ָ������ģʽ,   TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
	TIM_InitStructure.TIM_Polity    = PolityHigh;			//ָ���ж����ȼ�, PolityHigh,PolityLow
	TIM_InitStructure.TIM_Interrupt = ENABLE;				//�ж��Ƿ�����,   ENABLE��DISABLE
	TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_12T;			//ָ��ʱ��Դ,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
	TIM_InitStructure.TIM_ClkOut    = DISABLE;				//�Ƿ������������, ENABLE��DISABLE
	TIM_InitStructure.TIM_Value     = 65536UL - PWM_HIGH_MIN;	//��ֵ,
	TIM_InitStructure.TIM_Run       = ENABLE;				//�Ƿ��ʼ����������ʱ��, ENABLE��DISABLE
	Timer_Inilize(Timer0,&TIM_InitStructure);				//��ʼ��Timer0	  Timer0,Timer1,Timer2
//	
//	
	
	
// 	TIM_InitStructure1.TIM_Mode      = TIM_16Bit;	//ָ������ģʽ,   TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
//	TIM_InitStructure1.TIM_Polity    = PolityLow;			//ָ���ж����ȼ�, PolityHigh,PolityLow
//	TIM_InitStructure1.TIM_Interrupt = ENABLE;				//�ж��Ƿ�����,   ENABLE��DISABLE
//	TIM_InitStructure1.TIM_ClkSource = TIM_CLOCK_12T;			//ָ��ʱ��Դ,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
// 	TIM_InitStructure1.TIM_ClkOut    = DISABLE;				//�Ƿ������������, ENABLE��DISABLE
//	TIM_InitStructure1.TIM_Value     = 65536UL - PWM_HIGH_MIN1;	//��ֵ,
//	TIM_InitStructure1.TIM_Run       = ENABLE;				//�Ƿ��ʼ����������ʱ��, ENABLE��DISABLE
//	Timer_Inilize(Timer1,&TIM_InitStructure1);				//��ʼ��Timer0	  Timer0,Timer1,Timer2
//	
  
}

//========================================================================
// ����: u8	Timer_Inilize(u8 TIM, TIM_InitTypeDef *TIMx)
// ����: ��ʱ����ʼ������.
// ����: TIMx: �ṹ����,��ο�timer.h��Ķ���.
// ����: �ɹ�����0, �ղ�������1,���󷵻�2.
// �汾: V1.0,  
//========================================================================
u8	Timer_Inilize(u8 TIM, TIM_InitTypeDef *TIMx)
{
	if(TIM > Timer2)	return 1;	//�ղ���

	if(TIM == Timer0)
	{
		TR0 = 0;		//ֹͣ����
		if(TIMx->TIM_Interrupt == ENABLE)		ET0 = 1;	//�����ж�
		else									ET0 = 0;	//��ֹ�ж�
		if(TIMx->TIM_Polity == PolityHigh)		PT0 = 1;	//�����ȼ��ж�
		else									PT0 = 0;	//�����ȼ��ж�
		if(TIMx->TIM_Mode >  TIM_16BitAutoReloadNoMask)	return 2;	//����
		TMOD = (TMOD & ~0x03) | TIMx->TIM_Mode;	//����ģʽ,0: 16λ�Զ���װ, 1: 16λ��ʱ/����, 2: 8λ�Զ���װ, 3: 16λ�Զ���װ, ���������ж�
		if(TIMx->TIM_ClkSource == TIM_CLOCK_12T)	AUXR &= ~0x80;	//12T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_1T)		AUXR |=  0x80;	//1T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_Ext)	TMOD |=  0x04;	//����������Ƶ
		else										TMOD &= ~0x04;	//��ʱ
		if(TIMx->TIM_ClkOut == ENABLE)	INT_CLKO |=  0x01;	//���ʱ��
		else							INT_CLKO &= ~0x01;	//�����ʱ��
		
		TH0 = (u8)(TIMx->TIM_Value >> 8);
		TL0 = (u8)TIMx->TIM_Value;
		if(TIMx->TIM_Run == ENABLE)	TR0 = 1;	//��ʼ����

		return	0;		//�ɹ�
	}

if(TIM == Timer1)
	{
		TR1 = 0;		//ֹͣ����
		if(TIMx->TIM_Interrupt == ENABLE)		ET1 = 1;	//�����ж�
		else									ET1 = 0;	//��ֹ�ж�
		if(TIMx->TIM_Polity == PolityHigh)		PT1 = 1;	//�����ȼ��ж�
		else									PT1 = 0;	//�����ȼ��ж�
		if(TIMx->TIM_Mode >= TIM_16BitAutoReloadNoMask)	return 2;	//����
		TMOD = (TMOD & ~0x30) | TIMx->TIM_Mode;	//����ģʽ,0: 16λ�Զ���װ, 1: 16λ��ʱ/����, 2: 8λ�Զ���װ
		if(TIMx->TIM_ClkSource == TIM_CLOCK_12T)	AUXR &= ~0x40;	//12T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_1T)		AUXR |=  0x40;	//1T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_Ext)	TMOD |=  0x40;	//����������Ƶ
		else										TMOD &= ~0x40;	//��ʱ
		if(TIMx->TIM_ClkOut == ENABLE)	INT_CLKO |=  0x02;	//���ʱ��
		else							INT_CLKO &= ~0x02;	//�����ʱ��
		
		TH1 = (u8)(TIMx->TIM_Value >> 8);
		TL1 = (u8)TIMx->TIM_Value;
		if(TIMx->TIM_Run == ENABLE)	TR1 = 1;	//��ʼ����
		return	0;		//�ɹ�
	}

	if(TIM == Timer2)		//Timer2,�̶�Ϊ16λ�Զ���װ, �ж������ȼ�
	{
		AUXR &= ~(1<<4);	//ֹͣ����
		if(TIMx->TIM_Interrupt == ENABLE)			IE2  |=  (1<<2);	//�����ж�
		else										IE2  &= ~(1<<2);	//��ֹ�ж�
		if(TIMx->TIM_ClkSource >  TIM_CLOCK_Ext)	return 2;
		if(TIMx->TIM_ClkSource == TIM_CLOCK_12T)	AUXR &= ~(1<<2);	//12T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_1T)		AUXR |=  (1<<2);	//1T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_Ext)	AUXR |=  (1<<3);	//����������Ƶ
		else										AUXR &= ~(1<<3);	//��ʱ
		if(TIMx->TIM_ClkOut == ENABLE)	INT_CLKO |=  0x04;	//���ʱ��
		else							INT_CLKO &= ~0x04;	//�����ʱ��

		TH2 = (u8)(TIMx->TIM_Value >> 8);
		TL2 = (u8)TIMx->TIM_Value;
		if(TIMx->TIM_Run == ENABLE)	AUXR |=  (1<<4);	//��ʼ����
		return	0;		//�ɹ�
	}
	return 2;	//����
}

void Timer_Set(SYSTIMER *timer, INT32U alarm_time)
{
	timer->start_cnt = r_tickcnt;
	timer->alarm_time = alarm_time;	
}


INT32U Timer_GetElapse(SYSTIMER *timer)
{
	return	(r_tickcnt - timer->start_cnt) * RML_SYSTICK_TIME; 
}
void Timer_Reset(SYSTIMER *timer)
{
	
	timer->start_cnt = r_tickcnt=0;
 
}

 