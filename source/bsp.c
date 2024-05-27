#include  "../header/bsp.h"    // private library - BSP layer

//-----------------------------------------------------------------------------  
//           GPIO congiguration
//-----------------------------------------------------------------------------
void GPIOconfig(void){
 // volatile unsigned int i; // in case of while loop usage
  WDTCTL = WDTHOLD | WDTPW;		// Stop WDT
  
  
  /*
  // LEDs 8-bit Array Port configuration
  LEDsArrPortSel &= ~0xFF;            // GPIO capability
  LEDsArrPortDir |= 0xFF;             // output dir
  LEDsArrPort = 0x00;				  // clear all LEDs
  
  
  // Switches Setup
  SWsArrPortSel &= ~0x0F;
  SWsArrPortDir &= ~0x0F;
  */
  
//-------------------------------------------------------------
//            PushButtons setup
//-------------------------------------------------------------  
  PBsArrPortSel &= ~0x07;            // make P1.0 - P1.2 IO mode            
  PBsArrPortDir &= ~0x07;            // makes P1.0 - P1.2 Input mode  
  PBsArrIntEdgeSel |= 0x03;  	     // pull-up mode
  PBsArrIntEdgeSel &= ~0x0C;         // pull-down mode
  PBsArrIntEn |= 0x07;               // makes P1.0 - P1.2 Interrupt enable 
  PBsArrIntPend &= ~0xFF;            // clear pending interrupts for P1
  
//-------------------------------------------------------------
//            LCD setup
//-------------------------------------------------------------  
  LCD_Data_Sel &= ~0xF0 ;             // makes P1.4 - P1.7 IO mode
  LCD_Data_Dir |= 0xF0 ;              // makes P1.4 - P1.7 Output mode
  LCD_Data_Write &= ~0xF0 ;           // CLR P1.4 - P1.7 
  
  LCD_CTL_Sel &= ~0xE0 ;             // makes P2.5 - P2.7 IO mode
  LCD_CTL_Dir |= 0xE0 ;              // makes P2.5 - P2.7 Output mode
  LCd_CTL_Write &= ~0xE0 ;           // CLR P2.5 - P2.7 

  
//-------------------------------------------------------------
//            Generator setup
//-------------------------------------------------------------   


  
//-------------------------------------------------------------
//            Buzzer setup
//-------------------------------------------------------------   
  LCD_CTL_Sel &= ~0x04 ;             // makes P2.2 IO mode
  LCD_CTL_Dir |= 0x04 ;              // makes P2.2 Output mode
  LCd_CTL_Write &= ~0x04 ;           // CLR P2.2
  
//-------------------------------------------------------------
//            InputSignal setup
//-------------------------------------------------------------   
  LCD_CTL_Sel |= 0x10 ;             // makes P2.4  IO mode
  LCD_CTL_Dir &= 0x10 ;              // makes P2.4  Input mode
  //LCd_CTL_Write &= ~0x10 ;           // CLR P2.4
  
  
  _BIS_SR(GIE);                     // enable interrupts globally
  
}                             
//------------------------------------------------------------------------------------- 
//            Timers configuration 
//-------------------------------------------------------------------------------------
void TIMER0_A0_config(void){
  TA0CTL= TASSEL_2 + MC_0 + ID_3  ;     // select : 2 - SMCLK , control 0 : halted mode , divider 3 : /8
  TA0CCTL0 = CCIE ;                     // enable CCR0 
  //TA0CCR0 = 0xFFFF ;                    // makes TA0 CCR to FFFF
  TA0CCR0 = 0xFFFF ;                   // makes TA CCR to FFFF
  
  //__bis_SR_register(LPM0_bits + GIE);       // Enter LPM0 w/ interrupt

} 
void TIMER1_A1_config(void){
  TA1CTL= 0x0000 ;                           // CLR TA1 CNT
  TA1CCTL0 = 0x0010 ;                        // enable TA1 CCTL0
  TA1CCR0 = 0xFFFF ;                        // set TA1 CCR0 to 0xFFFF
  TA1R = 0x0000 ; ;                        // CLR TA1R
  TA1CCTL2 |= CM_1 + SCS + CAP + CCIE  ;   // CM :1 - Rising Edge , SCS :1 - Sync Cap , CAP :1 - Capture Mode , CCIE :1 - enable             
  TA1CTL |= TASSEL_2 + ID_3 + MC_3 +TAIE;  // TASSEL :2 - SMCLK , ID :3 - /8 ,MC :2 - Up mode
  __bis_SR_register(LPM0_bits + GIE);      // Go to sleep 
  
}

void TIMER1_A2_config(void){
  
}


//------------------------------------------------------------------------------------- 
//            ADC configuration 
//-------------------------------------------------------------------------------------
void ADCconfig(void){
  ADC10AE0 = 0x08 ;     // Select Input A3 
  ADC10CTL1 |= INCH_3 + ADC10DIV_1 + ADC10SSEL_3 + CONSEQ_2 ; 
  ADC10CTL0 |= ADC10SHT_3 + ADC10SR + MSC + ADC10IE +ADC10ON  ; 
}              

           
             

 
             
             
            
  

