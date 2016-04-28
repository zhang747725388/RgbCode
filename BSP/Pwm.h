


#ifndef	__PWM_H
#define	__PWM_H

 
#define		PWM_DUTY		18700			//����PWM�����ڣ���ֵΪʱ���������� 
#define		PWM_HIGH_MIN	225		//����PWM�������Сռ�ձȡ��û������޸ġ�
#define		PWM_HIGH_MAX	(PWM_DUTY-PWM_HIGH_MIN)	//����PWM��������ռ�ձȡ��û������޸ġ�

#define		PWM_DUTY1		18000			//����PWM�����ڣ���ֵΪʱ���������� 
#define		PWM_HIGH_MIN1	225		//����PWM�������Сռ�ձȡ��û������޸ġ�
#define		PWM_HIGH_MAX1	(PWM_DUTY1-PWM_HIGH_MIN1)	//����PWM��������ռ�ձȡ��û������޸ġ�


typedef enum //
{
  Duty1=69 ,	   // 3V
  Duty2=85 ,	  //
  Duty3=43 ,
  Duty4=43 ,
  Duty5=43
}Main_Duty;
/*************	���ر�������	**************/
 
extern u16		PWM_high,PWM_low;	//�м���� 
extern u16		PWM_high1,PWM_low1;	//�м���� 
extern void     SetNomalHighPwm(); 
 
#endif
