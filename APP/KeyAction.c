#include "rsystem.h"
SYSTIMER KEY_Tim;//按键时间基数
u8 keyflag=0;
void KeyAction(u8 flag){
  

			  switch(flag){


				    case KEY0_UP:
						pwm2  = 3000;	//PWM逐渐减到最小
 		      	LoadPWM(pwm2); 
						TX1_write2buff(PWM_low); 
					  break;	
				    case KEY1_UP: 	
								  pwm2  = 3100;	//PWM逐渐减到最小
		                   	LoadPWM(pwm2);
				     	PrintString1("Key2...\r\n");
					  break;
		        case KEY2_UP: 
 			     	PrintString1("Key3...\r\n");
					  break;
					  case KEY3_UP:	 
				   	PrintString1("Key4...\r\n");
					  break;
    }
}

void MainKeytask(void){

  			if(Timer_GetElapse(&KEY_Tim) >5){

          keyflag =Key_Scan();
		      KeyAction(keyflag);
       	  Timer_Reset(&KEY_Tim);
     }
 
}
 