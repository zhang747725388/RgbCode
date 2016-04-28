/*--- HEADER FILE DESCRIPTOR --------------------------------------------------
 
-----------------------------------------------------------------------------*/
#ifndef __DATATYPE_H_
#define __DATATYPE_H_
/*--- Header Includes -------------------------------------------------------*/
typedef  signed char				CHAR;
typedef  signed char				INT8S;
typedef  signed short int			INT16S;
typedef  signed int			        INT32S;
 
/* unsigned */
typedef  unsigned char				BYTE;
typedef  unsigned char				UCHAR;
typedef  unsigned char				uchar;
typedef  unsigned char				INT8U;
typedef  unsigned short int			INT16U;
typedef  unsigned int				INT32U; 
typedef  unsigned char	      u8;
typedef  unsigned int	        u16;
typedef  unsigned long	                        u32;

#define MAIN_Fosc		27000000L	//定义主时钟
//#define MAIN_Fosc		22118400L	//定义主时钟
//#define MAIN_Fosc		12000000L	//定义主时钟
//#define MAIN_Fosc		11059200L	//定义主时钟
//#define MAIN_Fosc		 5529600L	//定义主时钟
//#define MAIN_Fosc		24000000L	//定义主时钟

 /*   interrupt vector */
#define		INT0_VECTOR		0
#define		TIMER0_VECTOR	1
#define		INT1_VECTOR		2
#define		TIMER1_VECTOR	3
#define		UART1_VECTOR	4
#define		ADC_VECTOR		5
#define		LVD_VECTOR		6
#define		PCA_VECTOR		7
#define		UART2_VECTOR	8
#define		SPI_VECTOR		9
#define		INT2_VECTOR		10
#define		INT3_VECTOR		11
#define		TIMER2_VECTOR	12
#define		INT4_VECTOR		16
#define		UART3_VECTOR	17
#define		UART4_VECTOR	18
#define		TIMER3_VECTOR	19
#define		TIMER4_VECTOR	20
#define		CMP_VECTOR		21

#define		ENABLE		1
#define		DISABLE		0
sfr P_SW1 = 0xA2;
sfr PCON2   = 0x97;

#define	PolityLow			0	//低优先级中断
#define	PolityHigh			1	//高优先级中断


sbit PPCA = IP^7;	//PCA 中断 优先级设定位



sfr AUXR1 = 0xA2;


typedef struct systimer_t
{
	u8		start_cnt;
	u8		alarm_time;
}SYSTIMER;

sfr IE2   = 0xAF;	// 
sfr WAKE_CLKO = 0x8F;								 
sfr INT_CLKO = 0x8F;
sfr	AUXR2    = 0x8F;

#endif
