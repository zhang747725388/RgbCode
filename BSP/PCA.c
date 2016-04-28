 


#include "rsystem.h"
bit		B_Capture0,B_Capture1,B_Capture2,B_Capture3;
u8		PCA0_mode,PCA1_mode,PCA2_mode,PCA3_mode;
u16		CCAP0_tmp,PCA_Timer0;
u16		CCAP1_tmp,PCA_Timer1;
u16		CCAP2_tmp,PCA_Timer2;
u16		CCAP3_tmp,PCA_Timer3;

/*************	功能说明	**************


******************************************/

void	PCA_config(void)
{
	PCA_InitTypeDef		PCA_InitStructure;

	PCA_InitStructure.PCA_Clock    = PCA_Clock_1T;		//PCA_Clock_1T, PCA_Clock_2T, PCA_Clock_4T, PCA_Clock_6T, PCA_Clock_8T, PCA_Clock_12T, PCA_Clock_Timer0_OF, PCA_Clock_ECI
	PCA_InitStructure.PCA_IoUse    = PCA_P24_P25_P26_P27;	//PCA_P12_P11_P10_P37, PCA_P34_P35_P36_P37, PCA_P24_P25_P26_P27
	PCA_InitStructure.PCA_Interrupt_Mode = DISABLE;		//ENABLE, DISABLE
	PCA_InitStructure.PCA_Polity   = PolityLow;			//优先级设置	PolityHigh,PolityLow
	PCA_InitStructure.PCA_RUN      = DISABLE;			//ENABLE, DISABLE
	PCA_Init(PCA_Counter,&PCA_InitStructure);

//	PCA_InitStructure.PCA_Mode     = PCA_Mode_PWM;		//PCA_Mode_PWM, PCA_Mode_Capture, PCA_Mode_SoftTimer, PCA_Mode_HighPulseOutput
//	PCA_InitStructure.PCA_PWM_Wide = PCA_PWM_8bit;		//PCA_PWM_8bit, PCA_PWM_7bit, PCA_PWM_6bit
//	PCA_InitStructure.PCA_Interrupt_Mode = DISABLE;		//PCA_Rise_Active, PCA_Fall_Active, ENABLE, DISABLE
//	PCA_InitStructure.PCA_Value    = 128 << 8;			//对于PWM,高8位为PWM占空比
//	PCA_Init(PCA0,&PCA_InitStructure);

	PCA_InitStructure.PCA_Mode     = PCA_Mode_PWM;		//PCA_Mode_PWM, PCA_Mode_Capture, PCA_Mode_SoftTimer, PCA_Mode_HighPulseOutput
	PCA_InitStructure.PCA_PWM_Wide = PCA_PWM_7bit;		//PCA_PWM_8bit, PCA_PWM_7bit, PCA_PWM_6bit
	PCA_InitStructure.PCA_Interrupt_Mode = DISABLE;		//PCA_Rise_Active, PCA_Fall_Active, ENABLE, DISABLE
	PCA_InitStructure.PCA_Value    = 64 << 8;			//对于PWM,高8位为PWM占空比
	PCA_Init(PCA1,&PCA_InitStructure);

	PCA_InitStructure.PCA_Mode     = PCA_Mode_PWM;		//PCA_Mode_PWM, PCA_Mode_Capture, PCA_Mode_SoftTimer, PCA_Mode_HighPulseOutput
	PCA_InitStructure.PCA_PWM_Wide = PCA_PWM_6bit;		//PCA_PWM_8bit, PCA_PWM_7bit, PCA_PWM_6bit
	PCA_InitStructure.PCA_Interrupt_Mode = DISABLE;		//PCA_Rise_Active, PCA_Fall_Active, ENABLE, DISABLE
	PCA_InitStructure.PCA_Value    = 32 << 8;			//对于PWM,高8位为PWM占空比
	PCA_Init(PCA2,&PCA_InitStructure);
	
	
	
	PCA_InitStructure.PCA_Mode     = PCA_Mode_PWM;		//PCA_Mode_PWM, PCA_Mode_Capture, PCA_Mode_SoftTimer, PCA_Mode_HighPulseOutput
	PCA_InitStructure.PCA_PWM_Wide = PCA_PWM_6bit;		//PCA_PWM_8bit, PCA_PWM_7bit, PCA_PWM_6bit
	PCA_InitStructure.PCA_Interrupt_Mode = DISABLE;		//PCA_Rise_Active, PCA_Fall_Active, ENABLE, DISABLE
	PCA_InitStructure.PCA_Value    = 32 << 8;			//对于PWM,高8位为PWM占空比
	PCA_Init(PCA3,&PCA_InitStructure);

	CR = 1;
}


//========================================================================
// 函数: UpdatePwm(u8 PCA_id, u8 pwm_value)
// 描述: 更新PWM值. 
// 参数: PCA_id: PCA序号. 取值 PCA0,PCA1,PCA2,PCA_Counter
//		   pwm_value: pwm值, 这个值是输出低电平的时间.
// 返回: none.
// 版本: V1.0, 
//========================================================================
void	UpdatePwm(u8 PCA_id, u8 pwm_value)
{
	if(PCA_id == PCA0)	    CCAP0H = pwm_value;
	else if(PCA_id == PCA1)	CCAP1H = pwm_value;
	else if(PCA_id == PCA2)	CCAP2H = pwm_value;
	else if(PCA_id == PCA3)	CCAP3H = pwm_value;
}

//========================================================================
// 函数: void	PCA_Init(PCA_id, PCA_InitTypeDef *PCAx)
// 描述: PCA初始化程序.
// 参数: PCA_id: PCA序号. 取值 PCA0,PCA1,PCA2,PCA_Counter
//		 PCAx: 结构参数,请参考PCA.h里的定义.
// 返回: none.
// 版本: V1.0, 
//========================================================================
void	PCA_Init(u8 PCA_id, PCA_InitTypeDef *PCAx)
{
	if(PCA_id > PCA_Counter)	return;		//id错误

	if(PCA_id == PCA_Counter)			//设置公用Counter
	{
		CR = 0;
		CH = 0;
		CL = 0;
		AUXR1 = (AUXR1 & ~(3<<4)) | PCAx->PCA_IoUse;			//切换IO口
		CMOD  = (CMOD  & ~(7<<1)) | PCAx->PCA_Clock;			//选择时钟源
		CMOD  = (CMOD  & ~1) | (PCAx->PCA_Interrupt_Mode & 1);	//ECF
		if(PCAx->PCA_Polity == PolityHigh)		PPCA = 1;	//高优先级中断
		else									PPCA = 0;	//低优先级中断
		if(PCAx->PCA_RUN == ENABLE)	CR = 1;
		return;
	}

	PCAx->PCA_Interrupt_Mode &= (3<<4) + 1;
	if(PCAx->PCA_Mode >= PCA_Mode_SoftTimer)	PCAx->PCA_Interrupt_Mode &= ~(3<<4);

	if(PCA_id == PCA0)
	{
		CCAPM0    = PCAx->PCA_Mode | PCAx->PCA_Interrupt_Mode;	//工作模式, 中断模式
		PCA_PWM0  = (PCA_PWM0 & ~(3<<6)) | PCAx->PCA_PWM_Wide;	//PWM宽度

		PCA_Timer0 = PCAx->PCA_Value;
		B_Capture0 = 0;
		PCA0_mode = PCAx->PCA_Mode;
		CCAP0_tmp = PCA_Timer0;
		CCAP0L = (u8)CCAP0_tmp;			//将影射寄存器写入捕获寄存器，先写CCAP0L
		CCAP0H = (u8)(CCAP0_tmp >> 8);	//后写CCAP0H
	}
	if(PCA_id == PCA1)
	{
		CCAPM1    = PCAx->PCA_Mode | PCAx->PCA_Interrupt_Mode;
		PCA_PWM1  = (PCA_PWM1 & ~(3<<6)) | PCAx->PCA_PWM_Wide;

		PCA_Timer1 = PCAx->PCA_Value;
		B_Capture1 = 0;
		PCA1_mode = PCAx->PCA_Mode;
		CCAP1_tmp = PCA_Timer1;
		CCAP1L = (u8)CCAP1_tmp;			//将影射寄存器写入捕获寄存器，先写CCAP0L
		CCAP1H = (u8)(CCAP1_tmp >> 8);	//后写CCAP0H
	}
	if(PCA_id == PCA2)
	{
		CCAPM2    = PCAx->PCA_Mode | PCAx->PCA_Interrupt_Mode;
		PCA_PWM2  = (PCA_PWM2 & ~(3<<6)) | PCAx->PCA_PWM_Wide;

		PCA_Timer2 = PCAx->PCA_Value;
		B_Capture2 = 0;
		PCA2_mode = PCAx->PCA_Mode;
		CCAP2_tmp = PCA_Timer2;
		CCAP2L = (u8)CCAP2_tmp;			//将影射寄存器写入捕获寄存器，先写CCAP0L
		CCAP2H = (u8)(CCAP2_tmp >> 8);	//后写CCAP0H
	}
	
		if(PCA_id == PCA3)
	{
		CCAPM3    = PCAx->PCA_Mode | PCAx->PCA_Interrupt_Mode;
		PCA_PWM3  = (PCA_PWM3 & ~(3<<6)) | PCAx->PCA_PWM_Wide;

		PCA_Timer3 = PCAx->PCA_Value;
		B_Capture3 = 0;
		PCA3_mode = PCAx->PCA_Mode;
		CCAP3_tmp = PCA_Timer3;
		CCAP3L = (u8)CCAP3_tmp;			//将影射寄存器写入捕获寄存器，先写CCAP0L
		CCAP3H = (u8)(CCAP3_tmp >> 8);	//后写CCAP0H
	}
	
	
}


//========================================================================
// 函数: void	PCA_Handler (void) interrupt PCA_VECTOR
// 描述: PCA中断处理程序.
// 参数: None
// 返回: none.
// 版本: V1.0, 
//========================================================================
void	PCA_Handler (void) interrupt PCA_VECTOR
{
	if(CCF0)		//PCA模块0中断
	{
		CCF0 = 0;		//清PCA模块0中断标志
		if(PCA0_mode >= PCA_Mode_SoftTimer)		//PCA_Mode_SoftTimer and PCA_Mode_HighPulseOutput
		{
			CCAP0_tmp += PCA_Timer0;
			CCAP0L = (u8)CCAP0_tmp;			//将影射寄存器写入捕获寄存器，先写CCAP0L
			CCAP0H = (u8)(CCAP0_tmp >> 8);	//后写CCAP0H
		}
		else if(PCA0_mode == PCA_Mode_Capture)
		{
			CCAP0_tmp = CCAP0H;	//读CCAP0H
			CCAP0_tmp = (CCAP0_tmp << 8) + CCAP0L;
			B_Capture0 = 1;
		}
	}

	if(CCF1)	//PCA模块1中断
	{
		CCF1 = 0;		//清PCA模块1中断标志
		if(PCA1_mode >= PCA_Mode_SoftTimer)		//PCA_Mode_SoftTimer and PCA_Mode_HighPulseOutput
		{
			CCAP1_tmp += PCA_Timer1;
			CCAP1L = (u8)CCAP1_tmp;			//将影射寄存器写入捕获寄存器，先写CCAP0L
			CCAP1H = (u8)(CCAP1_tmp >> 8);	//后写CCAP0H
		}
		else if(PCA1_mode == PCA_Mode_Capture)
		{
			CCAP1_tmp = CCAP1H;	//读CCAP1H
			CCAP1_tmp = (CCAP1_tmp << 8) + CCAP1L;
			B_Capture1 = 1;
		}
	}

	if(CCF2)	//PCA模块2中断
	{
		CCF2 = 0;		//清PCA模块1中断标志
		if(PCA2_mode >= PCA_Mode_SoftTimer)		//PCA_Mode_SoftTimer and PCA_Mode_HighPulseOutput
		{
			CCAP2_tmp += PCA_Timer2;
			CCAP2L = (u8)CCAP2_tmp;			//将影射寄存器写入捕获寄存器，先写CCAP0L
			CCAP2H = (u8)(CCAP2_tmp >> 8);	//后写CCAP0H
		}
		else if(PCA2_mode == PCA_Mode_Capture)
		{
			CCAP2_tmp = CCAP2H;	//读CCAP2H
			CCAP2_tmp = (CCAP2_tmp << 8) + CCAP2L;
			B_Capture2 = 1;
		}
	}

	
		if(CCF3)	//PCA模块3中断
	{
		CCF3 = 0;		//清PCA模块1中断标志
		if(PCA3_mode >= PCA_Mode_SoftTimer)		//PCA_Mode_SoftTimer and PCA_Mode_HighPulseOutput
		{
			CCAP3_tmp += PCA_Timer3;
			CCAP3L = (u8)CCAP3_tmp;			//将影射寄存器写入捕获寄存器，先写CCAP0L
			CCAP3H = (u8)(CCAP3_tmp >> 8);	//后写CCAP0H
		}
		else if(PCA3_mode == PCA_Mode_Capture)
		{
			CCAP3_tmp = CCAP3H;	//读CCAP2H
			CCAP3_tmp = (CCAP3_tmp << 8) + CCAP3L;
			B_Capture3 = 1;
		}
	}
	
	if(CF)	//PCA溢出中断
	{
		CF = 0;			//清PCA溢出中断标志
	}

}