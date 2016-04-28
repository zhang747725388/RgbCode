
#include "rsystem.h"
 u8 DaswitchFlags=0;
void SetDa123Value(u8 Danum ,u8 flag){

	   switch(flag){
	   	case 0:
	   	   TLC5620_SetOutput(Danum,ZeroDA1);   //0
	   	break;
	  	case 1:
	   	   TLC5620_SetOutput(Danum,Minus_TwoDA1);
	   	break;
     	case 2:
	   	   TLC5620_SetOutput(Danum,Zero_FiveDA1);
	   	break;
    	case 3:
	   	   TLC5620_SetOutput(Danum,Four_NineDA1);
	   	break;
    	case 4:
	   	   TLC5620_SetOutput(Danum,Five_OneDA1);
	   	break;
    	case 5:
	   	   TLC5620_SetOutput(Danum,Eight_FiveDA1);
	   	break;
    	case 6:
	   	   TLC5620_SetOutput(Danum,TenDA1);
	   	break;
	 	case 7:
	   	   TLC5620_SetOutput(Danum,ElevenDA1);
	   	break;
	   }

 

}
void SetDa0Value( u8 flag){

	   switch(flag){   
	   	case 0:
	   	   TLC5620_SetOutput(0,ZeroDA0);   //0
	   	break;
	  	case 1:
	   	   TLC5620_SetOutput(0,ThreeDA0);
	   	break;
     	case 2:
	   	   TLC5620_SetOutput(0,FiveDA0);
	   	break;
     	  
	   }

 

}

 void DaHighset(u8 modelFlag){
    switch(modelFlag) {
     case 0:	//¹Ø±Õ
	 SetDa123Value(1,0);
     SetDa123Value(2,0);
	 SetDa123Value(3,0);
     SetDa0Value (0);
	 break;
	 case 1:	//gray
     SetDa123Value(1,5);
     SetDa123Value(2,5);
	 SetDa123Value(3,5);
     SetDa0Value(1);
	 break;
 	 case 2:  //white 
	 SetDa123Value(1,4);
     SetDa123Value(2,4);
	 SetDa123Value(3,4);
     SetDa0Value(1);
	 break;
 	 case 3:  //black
     SetDa123Value(1,7);   
     SetDa123Value(2,7);
	 SetDa123Value(3,7);
     SetDa0Value(1);
	 break;	
 	 case 4:  //R
	 SetDa123Value(1,4);
     SetDa123Value(2,6);
	 SetDa123Value(3,6);
     SetDa0Value(1);
	 break;	
 	 case 5:  //G
	 SetDa123Value(1,6);
     SetDa123Value(2,4);
	 SetDa123Value(3,6);
     SetDa0Value(1);
	 break;	
	  	 case 6:  //B
	 SetDa123Value(1,6);
     SetDa123Value(2,6);
	 SetDa123Value(3,4);
     SetDa0Value(1);
	 break;	
	  	 case 7:  //Odd
	 SetDa123Value(1,6);
     SetDa123Value(2,6);
	 SetDa123Value(3,6);
     SetDa0Value(2);
	 break;	
	  	 case 8:  //Even
	 SetDa123Value(1,6);
     SetDa123Value(2,6);
	 SetDa123Value(3,6);
     SetDa0Value(2);
	 break;
	 	}

 	 
 
 }

 void DaLowset(u8 modelFlag){
   
     switch(modelFlag) {
     case 0:	//¹Ø±Õ
	 SetDa123Value(1,0);  //-2
     SetDa123Value(2,0);
	 SetDa123Value(3,0);
     SetDa0Value (0);
	 break;
	 case 1:	//gray
     SetDa123Value(1,2);
     SetDa123Value(2,2);
	 SetDa123Value(3,2);
     SetDa0Value(1);
	 break;
 	 case 2:  //white 
	 SetDa123Value(1,3);
     SetDa123Value(2,3);
	 SetDa123Value(3,3);
     SetDa0Value(1);
	 break;
 	 case 3:  //black
     SetDa123Value(1,1);
     SetDa123Value(2,1);
	 SetDa123Value(3,1);
     SetDa0Value(1);
	 break;	
 	 case 4:  //R
	 SetDa123Value(1,3);
     SetDa123Value(2,0);
	 SetDa123Value(3,0);
     SetDa0Value (1);
	 break;	
 	 case 5:  //G
	 SetDa123Value(1,0);
     SetDa123Value(2,3);
	 SetDa123Value(3,0);
     SetDa0Value(1);
	 break;	
	  	 case 6:  //B
	 SetDa123Value(1,1);
     SetDa123Value(2,1);
	 SetDa123Value(3,3);
     SetDa0Value(1);
	 break;	
	  	 case 7:  //Odd
	 SetDa123Value(1,0);
     SetDa123Value(2,0);
	 SetDa123Value(3,0);
     SetDa0Value(2);
	 break;	
	  	 case 8:  //Even
	 SetDa123Value(1,0);
     SetDa123Value(2,0);
	 SetDa123Value(3,0);
     SetDa0Value(2);
	 break;	
	
	
	
	}
 }

  u8 SwitchDavalue(u8 flags,u8 modeflag){
   
 	  	 switch(flags){
		  case 0:  DaLowset(modeflag); return 0;
		  break;
		  case 1:  DaHighset(modeflag);	return 1;
		  break;
		 }
 
 }