#include "rsystem.h"
u16 pwm=0;
void main (void)
{	 
//    GPIO_config();
////   TLC5620_Init();
////   UART_config();
  	 Timer_config();
 	 EA=1;
//  	PCA_config();
////// 	
// 	PrintString1("Init UART1...\r\n");	//SUART1发送一个字符串
////// 
// pwm3=255-(255/4);
// pwm1=255-(255/4);
// pwm0=255-(255/16);
	
	
////  UpdatePwm(PCA0,pwm0);
////	UpdatePwm(PCA1,pwm1);
//   	SetChannelData(3,pwm2);
//		SetChannelData(1,pwm0);
////	UpdatePwm(PCA3,pwm3);
////TLC5620_AllOutput(dat1);
////	     SetChannelData(5,27);
// 		 //  SetChannelData(6,27);
//   TLC5620_SetOutput(0,170);
//	 TLC5620_SetOutput(1,175);
//   //      TLC5620_SetOutput(1,100);
//		  TLC5620_SetOutput(0,22);
//		  TLC5620_SetOutput(1,42);
//		  TLC5620_SetOutput(2,62);
//		  TLC5620_SetOutput(3,82);
////			 TLC5620_SetOutput(3,80);
////		   SetChannelData(8,27);
//   
//	   
   
 pwm = PWM_DUTY*1 / 10;	//给PWM一个初值，这里为10%占空比
//LoadPWM(pwm2);			//计算PWM重装值
LoadPWM(pwm);
// UpdatePwm(PCA3,pwm3);
// UpdatePwm(PCA2,pwm1);
// UpdatePwm(PCA1,pwm0);
 
//P15=1;
//P14=1;
  while(1)
   {
		 
	 
		 
//		 if(Timer_GetElapse(&Pwm_Tim) <20){
//	            TLC5620_SetOutput(0,22);
//			}	 
//		  if((Timer_GetElapse(&Pwm_Tim) >20)&&((Timer_GetElapse(&Pwm_Tim)<160))){
//	           TLC5620_SetOutput(0,122);
//              			
//			}	
//		  if(Timer_GetElapse(&Pwm_Tim) >160){
//// 	              	PrintString1("Init UART1...\r\n");	//SUART1发送一个字符串 
//				  TLC5620_SetOutput(0,22);
//                  Timer_Reset(&Pwm_Tim); 
//              			
//			}			


  
    MainKeytask(); 
// 	LoadPWM(pwmtt);			//计算PWM重装值
  }
}
 
 

 