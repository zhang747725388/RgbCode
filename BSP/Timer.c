/*************	功能说明	**************
 

******************************************/



#include "rsystem.h"
INT32U	r_tickcnt;	 
u8 uiflag=0;
/********************* Timer0中断函数************************/
void timer0_int (void) interrupt TIMER0_VECTOR
{
   	static INT32U tickcnt = 0;
   	  	static INT32U Autocnt = 0;
	if ( ++tickcnt >= RML_SYSTICK_TIME )
	{
	  tickcnt = 0;
	   Autocnt++;
	  r_tickcnt++;
//	  	PrintString1("Init UART1...\r\n");	//SUART1发送一个字符串
	
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

/********************* Timer1中断函数************************/
void timer1_int (void) interrupt TIMER1_VECTOR
{
 
	 
// 	  DaswitchFlags=!DaswitchFlags;
//	  if(SwitchDavalue(DaswitchFlags))
//	{
//		TH1 = (u8)(PWM_high1 >> 8);	//如果是输出低电平，则装载高电平时间。
//		TL1 = (u8)PWM_high1;
//   
//    
//	}
// 
//	else 	{
//		TH1 =  (u8)(PWM_low1 >> 8);	//如果是输出高电平，则装载低电平时间。
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

 
/************************ 定时器配置 ****************************/
void	Timer_config(void)
{
	
	TIM_InitTypeDef		TIM_InitStructure1;					//结构定义
	TIM_InitTypeDef		TIM_InitStructure;					//结构定义
	TIM_InitStructure.TIM_Mode      = TIM_16Bit;	//指定工作模式,   TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
	TIM_InitStructure.TIM_Polity    = PolityHigh;			//指定中断优先级, PolityHigh,PolityLow
	TIM_InitStructure.TIM_Interrupt = ENABLE;				//中断是否允许,   ENABLE或DISABLE
	TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_12T;			//指定时钟源,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
	TIM_InitStructure.TIM_ClkOut    = DISABLE;				//是否输出高速脉冲, ENABLE或DISABLE
	TIM_InitStructure.TIM_Value     = 65536UL - PWM_HIGH_MIN;	//初值,
	TIM_InitStructure.TIM_Run       = ENABLE;				//是否初始化后启动定时器, ENABLE或DISABLE
	Timer_Inilize(Timer0,&TIM_InitStructure);				//初始化Timer0	  Timer0,Timer1,Timer2
//	
//	
	
	
// 	TIM_InitStructure1.TIM_Mode      = TIM_16Bit;	//指定工作模式,   TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
//	TIM_InitStructure1.TIM_Polity    = PolityLow;			//指定中断优先级, PolityHigh,PolityLow
//	TIM_InitStructure1.TIM_Interrupt = ENABLE;				//中断是否允许,   ENABLE或DISABLE
//	TIM_InitStructure1.TIM_ClkSource = TIM_CLOCK_12T;			//指定时钟源,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
// 	TIM_InitStructure1.TIM_ClkOut    = DISABLE;				//是否输出高速脉冲, ENABLE或DISABLE
//	TIM_InitStructure1.TIM_Value     = 65536UL - PWM_HIGH_MIN1;	//初值,
//	TIM_InitStructure1.TIM_Run       = ENABLE;				//是否初始化后启动定时器, ENABLE或DISABLE
//	Timer_Inilize(Timer1,&TIM_InitStructure1);				//初始化Timer0	  Timer0,Timer1,Timer2
//	
  
}

//========================================================================
// 函数: u8	Timer_Inilize(u8 TIM, TIM_InitTypeDef *TIMx)
// 描述: 定时器初始化程序.
// 参数: TIMx: 结构参数,请参考timer.h里的定义.
// 返回: 成功返回0, 空操作返回1,错误返回2.
// 版本: V1.0,  
//========================================================================
u8	Timer_Inilize(u8 TIM, TIM_InitTypeDef *TIMx)
{
	if(TIM > Timer2)	return 1;	//空操作

	if(TIM == Timer0)
	{
		TR0 = 0;		//停止计数
		if(TIMx->TIM_Interrupt == ENABLE)		ET0 = 1;	//允许中断
		else									ET0 = 0;	//禁止中断
		if(TIMx->TIM_Polity == PolityHigh)		PT0 = 1;	//高优先级中断
		else									PT0 = 0;	//低优先级中断
		if(TIMx->TIM_Mode >  TIM_16BitAutoReloadNoMask)	return 2;	//错误
		TMOD = (TMOD & ~0x03) | TIMx->TIM_Mode;	//工作模式,0: 16位自动重装, 1: 16位定时/计数, 2: 8位自动重装, 3: 16位自动重装, 不可屏蔽中断
		if(TIMx->TIM_ClkSource == TIM_CLOCK_12T)	AUXR &= ~0x80;	//12T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_1T)		AUXR |=  0x80;	//1T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_Ext)	TMOD |=  0x04;	//对外计数或分频
		else										TMOD &= ~0x04;	//定时
		if(TIMx->TIM_ClkOut == ENABLE)	INT_CLKO |=  0x01;	//输出时钟
		else							INT_CLKO &= ~0x01;	//不输出时钟
		
		TH0 = (u8)(TIMx->TIM_Value >> 8);
		TL0 = (u8)TIMx->TIM_Value;
		if(TIMx->TIM_Run == ENABLE)	TR0 = 1;	//开始运行

		return	0;		//成功
	}

if(TIM == Timer1)
	{
		TR1 = 0;		//停止计数
		if(TIMx->TIM_Interrupt == ENABLE)		ET1 = 1;	//允许中断
		else									ET1 = 0;	//禁止中断
		if(TIMx->TIM_Polity == PolityHigh)		PT1 = 1;	//高优先级中断
		else									PT1 = 0;	//低优先级中断
		if(TIMx->TIM_Mode >= TIM_16BitAutoReloadNoMask)	return 2;	//错误
		TMOD = (TMOD & ~0x30) | TIMx->TIM_Mode;	//工作模式,0: 16位自动重装, 1: 16位定时/计数, 2: 8位自动重装
		if(TIMx->TIM_ClkSource == TIM_CLOCK_12T)	AUXR &= ~0x40;	//12T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_1T)		AUXR |=  0x40;	//1T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_Ext)	TMOD |=  0x40;	//对外计数或分频
		else										TMOD &= ~0x40;	//定时
		if(TIMx->TIM_ClkOut == ENABLE)	INT_CLKO |=  0x02;	//输出时钟
		else							INT_CLKO &= ~0x02;	//不输出时钟
		
		TH1 = (u8)(TIMx->TIM_Value >> 8);
		TL1 = (u8)TIMx->TIM_Value;
		if(TIMx->TIM_Run == ENABLE)	TR1 = 1;	//开始运行
		return	0;		//成功
	}

	if(TIM == Timer2)		//Timer2,固定为16位自动重装, 中断无优先级
	{
		AUXR &= ~(1<<4);	//停止计数
		if(TIMx->TIM_Interrupt == ENABLE)			IE2  |=  (1<<2);	//允许中断
		else										IE2  &= ~(1<<2);	//禁止中断
		if(TIMx->TIM_ClkSource >  TIM_CLOCK_Ext)	return 2;
		if(TIMx->TIM_ClkSource == TIM_CLOCK_12T)	AUXR &= ~(1<<2);	//12T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_1T)		AUXR |=  (1<<2);	//1T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_Ext)	AUXR |=  (1<<3);	//对外计数或分频
		else										AUXR &= ~(1<<3);	//定时
		if(TIMx->TIM_ClkOut == ENABLE)	INT_CLKO |=  0x04;	//输出时钟
		else							INT_CLKO &= ~0x04;	//不输出时钟

		TH2 = (u8)(TIMx->TIM_Value >> 8);
		TL2 = (u8)TIMx->TIM_Value;
		if(TIMx->TIM_Run == ENABLE)	AUXR |=  (1<<4);	//开始运行
		return	0;		//成功
	}
	return 2;	//错误
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

 