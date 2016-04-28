#ifndef	__TIMER_H
#define	__TIMER_H
extern INT32U r_tickcnt ;
#include "rsystem.h"

#define	Timer0						0
#define	Timer1						1
#define	Timer2						2
#define	Timer3						3
#define	Timer4						4

#define	TIM_16BitAutoReload			0
#define	TIM_16Bit					1
#define	TIM_8BitAutoReload			2
#define	TIM_16BitAutoReloadNoMask	3

#define	TIM_CLOCK_1T				0
#define	TIM_CLOCK_12T				1
#define	TIM_CLOCK_Ext				2
//#define		PWM_DUTY		6000			//定义PWM的周期，数值为时钟周期数，假如使用27.576MHZ的主频，则PWM频率为6000HZ。

//#define		PWM_HIGH_MIN	2700			//限制PWM输出的最小占空比。用户请勿修改。
//#define		PWM_HIGH_MAX	(PWM_DUTY-PWM_HIGH_MIN)	//限制PWM输出的最大占空比。用户请勿修改。
typedef struct
{
	u8	TIM_Mode;		//工作模式,  	TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
	u8	TIM_Polity;		//优先级设置	PolityHigh,PolityLow
	u8	TIM_Interrupt;	//中断允许		ENABLE,DISABLE
	u8	TIM_ClkSource;	//时钟源		TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
	u8	TIM_ClkOut;		//可编程时钟输出,	ENABLE,DISABLE
	u16	TIM_Value;		//装载初值
	u8	TIM_Run;		//是否运行		ENABLE,DISABLE
} TIM_InitTypeDef;
extern  void	Timer_config(void);
extern u8	Timer_Inilize(u8 TIM, TIM_InitTypeDef *TIMx);
extern void Timer_Set(SYSTIMER *timer, INT32U alarm_time);
extern INT32U Timer_GetElapse(SYSTIMER *timer);
extern void Timer_Reset(SYSTIMER *timer);
#endif
