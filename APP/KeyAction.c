#include "rsystem.h"
SYSTIMER KEY_Tim;//����ʱ�����
u8 keyflag=0;
u8 OpenFlag=0;
u8 AutoFlag=0;
void KeyAction(u8 flag){
  

			  switch(flag){


				    case KEY0_UP:     //����
					   	 if(OpenFlag==1){
						   
					            modelflag=modelflag+1;
								SetNomalHighPwm();
						  	  if(modelflag>8){
							  			 modelflag=0;
										   SetNomalHighPwm();
											 OpenFlag=0;     
							  
							  }
						 }
					 	 
					  break;	
				    case KEY1_UP: 	 //����
						
					 	 	 if(OpenFlag==1){
						   
					            modelflag=modelflag-1;
								  SetNomalHighPwm();
						  	  if(modelflag<1){
							  modelflag=0;
							    SetNomalHighPwm();
								 OpenFlag=0;
							  }
						 }	 
					 		  
					  break;
		        case KEY2_UP: 		//�򿪹ر�
 			      		    	   OpenFlag=!OpenFlag;
					           	if(OpenFlag==1){
								
								  	OpenPower();
									 modelflag=1;
								} else{
								
								   ModeOff();
								    OpenFlag=0;	
									 modelflag=0;
								
								}

						   
					  
					  break;
					  case KEY3_UP:			   //�Զ��ֶ��л�
					  AutoFlag=!AutoFlag;
				   			  
					  break;
    }
}

void MainKeytask(void){

  			if(Timer_GetElapse(&KEY_Tim) >3){

              keyflag =Key_Scan();
		      KeyAction(keyflag);
       	      Timer_Reset(&KEY_Tim);
     }
 
}
 