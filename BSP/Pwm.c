 

/*************	功能说明	**************

******************************************/
 
#include "rsystem.h"
 /**************** 计算PWM重装值函数 *******************/
u16	PWM_high,PWM_low;	//中间变量 

u16	PWM_high1,PWM_low1;	//中间变量 
void	LoadPWM(u16 i)
{
	u16	j;

	if(i > PWM_HIGH_MAX)		i = PWM_HIGH_MAX;	//如果写入大于最大占空比数据，则强制为最大占空比。
	if(i < PWM_HIGH_MIN)		i = PWM_HIGH_MIN;	//如果写入小于最小占空比数据，则强制为最小占空比。
	j = 65536UL - PWM_DUTY + i;	//计算PWM低电平时间
	i = 65536UL - i;		      	//计算PWM高电平时间
	EA = 0;
	PWM_high = i;	//装载PWM高电平时间
	PWM_low  = j;	//装载PWM低电平时间
	EA = 1;
}
 
void	LoadPWM1(u16 i)
{
	u16	j;

	if(i > PWM_HIGH_MAX1)		i = PWM_HIGH_MAX1;	//如果写入大于最大占空比数据，则强制为最大占空比。
	if(i < PWM_HIGH_MIN1)		i = PWM_HIGH_MIN1;	//如果写入小于最小占空比数据，则强制为最小占空比。
	j = 65536UL - PWM_DUTY1 + i;	//计算PWM低电平时间
	i = 65536UL - i;		      	//计算PWM高电平时间
	EA = 0;
	PWM_high1 = i;	//装载PWM高电平时间
	PWM_low1  = j;	//装载PWM低电平时间
	EA = 1;
}
void SetPwmMode123(){
  switch(modelflag){
  case 0:	LoadPWM(0);break;
  case 1:	LoadPWM(7448);break;
  case 2:	LoadPWM(7448);break;
  case 3:	LoadPWM(3723);break;
  case 4:	LoadPWM(3590);break;
  case 5:	LoadPWM(3590);break;
  case 6:	LoadPWM(3590);break;
  case 7:	LoadPWM(200);break;
  case 8:	LoadPWM(2610);break;
  
  }
    
}
 
void SetNomalHighPwm(){
  	   SetPwmMode123();
   	  LoadPWM1(PWM_DUTY1/2);
}


 