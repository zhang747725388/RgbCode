


#ifndef	__PWM_H
#define	__PWM_H

 
#define		PWM_DUTY		6000			//����PWM�����ڣ���ֵΪʱ���������� 

#define		PWM_HIGH_MIN	32			//����PWM�������Сռ�ձȡ��û������޸ġ�
#define		PWM_HIGH_MAX	(PWM_DUTY-PWM_HIGH_MIN)	//����PWM��������ռ�ձȡ��û������޸ġ�

/*************	���ر�������	**************/
 
extern u16		PWM_high,PWM_low;	//�м���� 
extern void  	LoadPWM(u16 i);
#endif
