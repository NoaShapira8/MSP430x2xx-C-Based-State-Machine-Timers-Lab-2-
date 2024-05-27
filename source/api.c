#include  "../header/api.h"    		// private library - API layer
#include  "../header/halGPIO.h"     // private library - HAL layer
#include "stdio.h" 


void CountUp (void) { 
  
  
  if(counter ==1) { 
    lcd_home(); 
    char const * minstr ="00:";
    lcd_puts(minstr); 
    lcd_data(tens) ; 
    lcd_data(singles) ; 
  }
  else if (counter <61 ) {
    singles=singles +1 ; 
    if(singles==0x3A ) {
      tens = tens +1 ; 
      singles= 0x30 ; 
    }
    
    lcd_cursor_left(); 
    lcd_cursor_left();
    lcd_data(tens) ; 
    lcd_data(singles) ; 
  }
  else if ( counter == 61 ) {
    lcd_home() ; 
    char const * OneMin ="01:00";
    lcd_puts(OneMin) ;
    flag=2 ; 
    counter=0 ; 
    
  }
  Timer_A0_On() ;
}


void CountDown (void) {
    
  
  if(counter ==1) { 
    lcd_home(); 
    char const * minstr ="00:";
    lcd_puts(minstr); 
    singles= 0x39 ;
    tens = 0x35 ; 
    lcd_data(tens) ; 
    lcd_data(singles) ;
    Timer_A0_On() ; 
    
  }
  else if (counter <60 ) {
    singles=singles -1 ; 
    if(singles==0x2F ) {
      tens = tens -1 ; 
      singles= 0x39 ; 
    }
    
    lcd_cursor_left(); 
    lcd_cursor_left();
    lcd_data(tens) ; 
    lcd_data(singles) ; 
    Timer_A0_On() ; 
  }
  else if ( counter == 60 ) {
    lcd_home() ; 
    char const * ZeroMin ="00:00";
    lcd_puts(ZeroMin) ;
    Timer_A0_On() ; 
    
  }
  
  else if ( counter ==61 ) { 
    Timer_A0_Off () ; 
    lcd_clear() ; 
    lcd_home() ; 
    state=state0 ; 
    counter = 0 ; 
    flag = 0 ; 
  }
}


void Timer_A0_Off (void ) { 
  TA0CTL = 0x0000 ; 
  TA0CCTL0 = 0x0000 ; 
} 

  

void Timer_A0_On (void) {
  TA0CTL = MC_2 + TAIE +  ID_3 + TASSEL_2 ; 
  TA0CCTL0 |=CCIE ; 
  //__bis_SR_register(LPM0_bits + GIE);       // Enter LPM0 w/ interrupt
  
  
}


void Timer_A1_On (void) {
  TA1CCR0 = 0xFFFF ; 
  TA1CTL |= MC_1 + TAIE + TASSEL_2 ;
  TA1CCTL2 |= CCIE + CM_1 + CAP + SCS + CCIS_0; 
   __bis_SR_register(LPM0_bits + GIE);       // Enter LPM0 w/ interrupt


}


void printFreq (void) { 
  if ( Flag_func2==1 ) {
    const char  Fin[] ="Fin=";
    const char  Hz[] ="Hz";
    lcd_home() ; 
    lcd_puts(Fin) ; 
    real_freq = (unsigned int) Freq_Count ; 
    sprintf(StrFreq ,"%d" ,real_freq ) ; 
    lcd_puts(StrFreq) ; 
    lcd_puts(Hz) ; 
    Flag_func2 =0 ;
    __bis_SR_register(LPM0_bits + GIE); 
    
  }
  else {
    __bis_SR_register(LPM0_bits + GIE); 
  }
}

void Func3(void) {
  LCD_CTL_Dir |= 0x04 ; 
  ADCconfig() ;
  ADC10CTL0 |= ENC + ADC10SC ;  // Start the ADC 
  __bis_SR_register(LPM0_bits + GIE);       // Enter LPM0 w/ interrupt
  
  
}
void Calc_N_Fout(void) { 
  N_ADC= (int)ADC10MEM ; 
  N_Fout = (int)(m* N_ADC + 1023) ; 
  Timer_func_3() ; 

}

void Timer_func_3 (void) {
  TA1CTL &= ~0xFFFF ;           
  TA1R &= ~0xFFFF ; 
  TA1CCR0 = N_Fout/2  ; 
  TA1CCTL0 |= CCIE ; 
  TA1CTL |= TASSEL_2 + MC_1  ; 

}


  
void ADC_Off (void) { 
  ADC10AE0 = 0x00 ;     // Select Input A3 
  ADC10CTL1 = 0x0000 ; 
  ADC10CTL0 = 0x0000 ; 
  TA1CTL &= ~0xFFFF ;         
  TA1R &= ~0xFFFF ; 
  TACCTL0 &= ~0xFFFF ; 
  
}

  
  

