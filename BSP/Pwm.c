 

/*************	����˵��	**************

******************************************/
 
#include "rsystem.h"
 /**************** ����PWM��װֵ���� *******************/
u16	PWM_high,PWM_low;	//�м���� 
void	LoadPWM(u16 i)
{
	u16	j;

	if(i > PWM_HIGH_MAX)		i = PWM_HIGH_MAX;	//���д��������ռ�ձ����ݣ���ǿ��Ϊ���ռ�ձȡ�
	if(i < PWM_HIGH_MIN)		i = PWM_HIGH_MIN;	//���д��С����Сռ�ձ����ݣ���ǿ��Ϊ��Сռ�ձȡ�
	j = 65536UL - PWM_DUTY + i;	//����PWM�͵�ƽʱ��
	i = 65536UL - i;		      	//����PWM�ߵ�ƽʱ��
	EA = 0;
	PWM_high = i;	//װ��PWM�ߵ�ƽʱ��
	PWM_low  = j;	//װ��PWM�͵�ƽʱ��
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