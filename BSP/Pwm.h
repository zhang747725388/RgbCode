


#ifndef	__PWM_H
#define	__PWM_H

 
#define		PWM_DUTY		6000			//定义PWM的周期，数值为时钟周期数， 

#define		PWM_HIGH_MIN	32			//限制PWM输出的最小占空比。用户请勿修改。
#define		PWM_HIGH_MAX	(PWM_DUTY-PWM_HIGH_MIN)	//限制PWM输出的最大占空比。用户请勿修改。

/*************	本地变量声明	**************/
 
extern u16		PWM_high,PWM_low;	//中间变量 
extern void  	LoadPWM(u16 i);
#endif
