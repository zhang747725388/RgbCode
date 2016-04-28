 

/*************	����˵��	**************

******************************************/
 
#include "rsystem.h"
 /**************** ����PWM��װֵ���� *******************/
u16	PWM_high,PWM_low;	//�м���� 

u16	PWM_high1,PWM_low1;	//�м���� 
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
 
void	LoadPWM1(u16 i)
{
	u16	j;

	if(i > PWM_HIGH_MAX1)		i = PWM_HIGH_MAX1;	//���д��������ռ�ձ����ݣ���ǿ��Ϊ���ռ�ձȡ�
	if(i < PWM_HIGH_MIN1)		i = PWM_HIGH_MIN1;	//���д��С����Сռ�ձ����ݣ���ǿ��Ϊ��Сռ�ձȡ�
	j = 65536UL - PWM_DUTY1 + i;	//����PWM�͵�ƽʱ��
	i = 65536UL - i;		      	//����PWM�ߵ�ƽʱ��
	EA = 0;
	PWM_high1 = i;	//װ��PWM�ߵ�ƽʱ��
	PWM_low1  = j;	//װ��PWM�͵�ƽʱ��
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


 