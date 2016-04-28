#include "rsystem.h"
u8 modelflag=0;
 u8 DaFlagSwith=0;
void OpenPower(){

  P21=1;  
  P15=1;  
  
P37=1;
P16=1;
P17=0;
 UpdatePwm(PCA3,145);
 UpdatePwm(PCA2,199);
 UpdatePwm(PCA1,241);


}
 void ClosePower(){

  P21=0;  
  P15=0;  
  
P37=0;
P16=0;
P17=0;
P10=0;
P11=0;
P12=0;
P13=0;
 UpdatePwm(PCA3,255);
 UpdatePwm(PCA2,255);
 UpdatePwm(PCA1,255);


}
void ModeOFF(){

	ClosePower();
   SwitchDavalue(0,0);
   SwitchDavalue(1,0);

}

/****************************************
***ǰ����DAоƬ��ѹ���ǵ͵�ƽ 0.5(28)V��DAֵ�� �ߵ�ƽ��8.5V(69)	���ĸ�3V AD 69 
***	��2�����ǵ͵�ƽ-8V���ߵ�ƽ17V�����и��㶨����30V
**************************************/
void ModelGray(){
P13=~P13;
P10=~P10;
P11=~P11;
P12=~P12; 
	if(P13)
	{
		TH0 = (u8)(PWM_high >> 8);	//���������͵�ƽ����װ�ظߵ�ƽʱ�䡣
		TL0 = (u8)PWM_high;
	}
	else 	{
		TH0 =  (u8)(PWM_low >> 8);	//���������ߵ�ƽ����װ�ص͵�ƽʱ�䡣
		TL0 = (u8)PWM_low;
		DaFlagSwith++;
		    if(DaFlagSwith>1){	DaFlagSwith=0;	}
	 
	}





}
/****************************************
***ǰ����DAоƬ��ѹ���ǵ͵�ƽ 4.9V()��DAֵ�� �ߵ�ƽ��5.1(54)V	���ĸ�3V
***	��2�����ǵ͵�ƽ-8V���ߵ�ƽ17V�����и��㶨����30V
**************************************/
void ModelWhite(){


	P13=~P13;
P10=~P10;
P11=~P11;
P12=~P12; 
	if(P13)
	{
		TH0 = (u8)(PWM_high >> 8);	//���������͵�ƽ����װ�ظߵ�ƽʱ�䡣
		TL0 = (u8)PWM_high;
	}
	else 	{
		TH0 =  (u8)(PWM_low >> 8);	//���������ߵ�ƽ����װ�ص͵�ƽʱ�䡣
		TL0 = (u8)PWM_low;
		DaFlagSwith++;
	 
	}
 

   




}
/****************************************
***ǰ����DAоƬ��ѹ���ǵ͵�ƽ -2��DAֵ�� �ߵ�ƽ��11	���ĸ�3V
***	��2�����ǵ͵�ƽ-8V���ߵ�ƽ17V�����и��㶨����30V
**************************************/
void ModelBlack(){


	P13=~P13;
P10=~P10;
P11=~P11;
P12=~P12; 
	if(P13)
	{
		TH0 = (u8)(PWM_high >> 8);	//���������͵�ƽ����װ�ظߵ�ƽʱ�䡣
		TL0 = (u8)PWM_high;
	}
	else 	{
		TH0 =  (u8)(PWM_low >> 8);	//���������ߵ�ƽ����װ�ص͵�ƽʱ�䡣
		TL0 = (u8)PWM_low;
		DaFlagSwith++;
	}

    


}
 /****************************************
***ǰ2��DAоƬ��ѹ���ǵ͵�ƽ 4.9V��DAֵ�� �ߵ�ƽ��5.1V �������ǵ͵�ƽ0 ���ߵ�ƽ10V	���ĸ�3V
***	��2�����ǵ͵�ƽ-8V���ߵ�ƽ17V�����и��㶨����30V
**************************************/
void ModelR(){



	P13=~P13;
P10=~P10;
P11=~P11;
P12=~P12; 
	if(P13)
	{
		TH0 = (u8)(PWM_high >> 8);	//���������͵�ƽ����װ�ظߵ�ƽʱ�䡣
		TL0 = (u8)PWM_high;
	}
	else 	{
		TH0 =  (u8)(PWM_low >> 8);	//���������ߵ�ƽ����װ�ص͵�ƽʱ�䡣
		TL0 = (u8)PWM_low;
		DaFlagSwith++;
	}

  


}
/****************************************
*** ��1��DAоƬ��ѹ���ǵ͵�ƽ 0v��DAֵ�� �ߵ�ƽ��10  2.  4.9(53),5.1 3.  0,10	���ĸ�3V
***	��2�����ǵ͵�ƽ-8V���ߵ�ƽ17V�����и��㶨����30V
**************************************/
void ModelG(){


 P13=~P13;
P10=~P10;
P11=~P11;
P12=~P12; 
	if(P13)
	{
		TH0 = (u8)(PWM_high >> 8);	//���������͵�ƽ����װ�ظߵ�ƽʱ�䡣
		TL0 = (u8)PWM_high;
	}
	else 	{
		TH0 =  (u8)(PWM_low >> 8);	//���������ߵ�ƽ����װ�ص͵�ƽʱ�䡣
		TL0 = (u8)PWM_low;
		DaFlagSwith++;
	}
 



}
/****************************************
***��1��DAоƬ��ѹ���ǵ͵�ƽ -2v��DAֵ�� �ߵ�ƽ��10  2.  -2(20) ,10(82) 3.  4.9,5.1	���ĸ�3V
***	��2�����ǵ͵�ƽ-8V���ߵ�ƽ17V�����и��㶨����30V
**************************************/
void ModelB(){


  P13=~P13;
P10=~P10;
P11=~P11;
P12=~P12; 
	if(P13)
	{
		TH0 = (u8)(PWM_high >> 8);	//���������͵�ƽ����װ�ظߵ�ƽʱ�䡣
		TL0 = (u8)PWM_high;
	}
	else 	{
		TH0 =  (u8)(PWM_low >> 8);	//���������ߵ�ƽ����װ�ص͵�ƽʱ�䡣
		TL0 = (u8)PWM_low;
		DaFlagSwith++;
	}

   



}
/****************************************
***ǰ����DAоƬ��ѹ���ǵ͵�ƽ 0��DAֵ�� �ߵ�ƽ��10V	���ĸ�5V 85
***	��2�����ǵ͵�ƽ-8V���ߵ�ƽ17V�����и��㶨����30V
**************************************/
void ModelOdd(){



	 P13=~P13;
P10=~P10;
P11=~P11;
P12=~P12; 
	if(P13)
	{
		TH0 = (u8)(PWM_high >> 8);	//���������͵�ƽ����װ�ظߵ�ƽʱ�䡣
		TL0 = (u8)PWM_high;
	}
	else 	{
		TH0 =  (u8)(PWM_low >> 8);	//���������ߵ�ƽ����װ�ص͵�ƽʱ�䡣
		TL0 = (u8)PWM_low;
		DaFlagSwith++;
	}

 



}
/****************************************
***ǰ����DAоƬ��ѹ���ǵ͵�ƽ 0��DAֵ�� �ߵ�ƽ��10V	���ĸ�5V	85
***	��2�����ǵ͵�ƽ-8V���ߵ�ƽ17V�����и��㶨����30V
**************************************/
void ModelEven(){


	 P13=~P13;
P10=~P10;
P11=~P11;
P12=~P12; 
	if(P13)
	{
		TH0 = (u8)(PWM_high >> 8);	//���������͵�ƽ����װ�ظߵ�ƽʱ�䡣
		TL0 = (u8)PWM_high;
	}
	else 	{
		TH0 =  (u8)(PWM_low >> 8);	//���������ߵ�ƽ����װ�ص͵�ƽʱ�䡣
		TL0 = (u8)PWM_low;
		DaFlagSwith++;
	}

  



}
void SwitchModel(){

switch(modelflag){

case 1:
	ModelGray();
	break;
case 2:
	ModelWhite();
	break;
case 3:
	ModelBlack();
	break;
case 4:
	ModelR();
	break;
case 5:
	ModelG();
	break;
case 6:
	ModelB();
	break;
case 7:
	ModelOdd();
	break;
case 8:
	ModelEven();
	break;
case 0:
	ModeOFF();
	break;

} 

}
void SetDaModeValue(u8 ModelFlag){
 

  if(DaFlagSwith>1){
	
		  DaFlagSwith=0;
	
	}
	switch(DaFlagSwith){
     case 1: SwitchDavalue(1,ModelFlag)	;
	 break;
	
	case 0:	 SwitchDavalue(0,ModelFlag);
	break;
	 
	}
	   if(DaFlagSwith>2){
	
		  DaFlagSwith=0;
	
	}



}