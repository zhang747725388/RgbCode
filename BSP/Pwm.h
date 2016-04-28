


#ifndef	__PWM_H
#define	__PWM_H

 
#define		PWM_DUTY		18700			//定义PWM的周期，数值为时钟周期数， 
#define		PWM_HIGH_MIN	225		//限制PWM输出的最小占空比。用户请勿修改。
#define		PWM_HIGH_MAX	(PWM_DUTY-PWM_HIGH_MIN)	//限制PWM输出的最大占空比。用户请勿修改。

#define		PWM_DUTY1		18000			//定义PWM的周期，数值为时钟周期数， 
#define		PWM_HIGH_MIN1	225		//限制PWM输出的最小占空比。用户请勿修改。
#define		PWM_HIGH_MAX1	(PWM_DUTY1-PWM_HIGH_MIN1)	//限制PWM输出的最大占空比。用户请勿修改。


typedef enum //
{
  Duty1=69 ,	   // 3V
  Duty2=85 ,	  //
  Duty3=43 ,
  Duty4=43 ,
  Duty5=43
}Main_Duty;
/*************	本地变量声明	**************/
 
extern u16		PWM_high,PWM_low;	//中间变量 
extern u16		PWM_high1,PWM_low1;	//中间变量 
extern void     SetNomalHighPwm(); 
 
#endif
