#ifndef _bsp_H_
#define _bsp_H_

#include  <msp430g2553.h>          // MSP430x2xx
// #include  <msp430xG46x.h>  // MSP430x4xx


#define   debounceVal      250

//-------------------------------------------------------------
//            LEDs abstraction
//-------------------------------------------------------------
/*
#define   LEDs_SHOW_RATE   0xFFFF  // 62_5ms
#define LEDsArrPort        P1OUT
#define LEDsArrPortDir     P1DIR
#define LEDsArrPortSel     P1SEL


//-------------------------------------------------------------
//            Switches abstraction
//-------------------------------------------------------------
#define SWsArrPort         P2IN
#define SWsArrPortDir      P2DIR
#define SWsArrPortSel      P2SEL
#define SWmask             0x0F
*/

//-------------------------------------------------------------
//            PushButtons abstraction
//-------------------------------------------------------------

#define PBsArrPort	   P1IN 
#define PBsArrIntPend	   P1IFG 
#define PBsArrIntEn	   P1IE
#define PBsArrIntEdgeSel   P1IES
#define PBsArrPortSel      P1SEL 
#define PBsArrPortDir      P1DIR 
#define PB0                0x01
#define PB1                0x02
#define PB2                0x04

//-------------------------------------------------------------
//            LCD abstraction
//-------------------------------------------------------------
// LCD Data 
#define LCD_Data_Sel    P1SEL
#define LCD_Data_Dir    P1DIR
#define LCD_Data_Write  P1OUT
#define LCD_Data_Read   P1IN

// LCD Control 
#define LCD_CTL_Sel     P2SEL
#define LCD_CTL_Dir     P2DIR
#define LCd_CTL_Write   P2OUT

//-------------------------------------------------------------
//            Generator abstraction
//-------------------------------------------------------------   
  
  
  
  
//-------------------------------------------------------------
//            Buzzer abstraction
//-------------------------------------------------------------   
  
  
//-------------------------------------------------------------
//            InputSignal abstraction
//-------------------------------------------------------------   
  


//-------------------------------------------------------------
//            Functions
//-------------------------------------------------------------
extern void GPIOconfig(void);
extern void TIMER0_A0_config(void);
extern void TIMER1_A1_config(void);
extern void TIMER1_A2_config(void);
extern void ADCconfig(void);

#endif



