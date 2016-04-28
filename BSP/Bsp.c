
#include "rsystem.h"
 
 void BspInit(){
     GPIO_config();
     TLC5620_Init();
  	 Timer_config();
 	 PCA_config();
 	 EA=1;
//	 	UART_config();
 	 SetNomalHighPwm();
 	ModeOFF();
 }

