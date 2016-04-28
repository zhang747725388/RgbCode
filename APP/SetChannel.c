#include "rsystem.h"
u16	pwm0,pwm1,pwm2,pwm3;

void SetChannelData(u8 channel,u8  datavalue){
	switch(channel){
  case 1:UpdatePwm(PCA0,datavalue);
		break;
  case 2:UpdatePwm(PCA1,datavalue);
		break;
  case 3:UpdatePwm(PCA2,datavalue);
		break;
  case 4:UpdatePwm(PCA3,datavalue);
		break;
  case 5:
		TLC5620_SetOutput(CHL0,datavalue);
		break;
  case 6: 
		TLC5620_SetOutput(CHL1,datavalue);
		break;
  case 7: 
		TLC5620_SetOutput(CHL2,datavalue);
		break;	
  case 8:
     	TLC5620_SetOutput(CHL3,datavalue);
		break;		
}
 
}


