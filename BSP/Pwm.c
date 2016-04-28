 

/*************	功能说明	**************

******************************************/
 
#include "rsystem.h"
 /**************** 计算PWM重装值函数 *******************/
u16	PWM_high,PWM_low;	//中间变量 
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

void SetTimerPwm(u8 flag){

switch(flag){

case 1:
	 TLC5620_SetOutput(0,122);
	break;
case 0:
	 TLC5620_SetOutput(0,22);
	break;



}


}