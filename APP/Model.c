#include "rsystem.h"
u8 modelflag=0;
void ModeOFF(){




}
void Model1(){







}
void Model2(){







}
void Model3(){







}

void Model4(){







}

void Model5(){







}
void SwitchModel(){

switch(modelflag){

case 1:
	Model1();
	break;

case 2:
	Model2();
	break;

case 3:
	Model3();
	break;
case 4:
	Model4();
	break;
case 5:
	Model5();
	break;
case 0:
	ModeOFF();
	break;

}




}