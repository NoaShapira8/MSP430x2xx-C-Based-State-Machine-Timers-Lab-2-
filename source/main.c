#include  "../header/api.h"    		// private library - API layer
#include  "../header/app.h"    		// private library - APP layer

enum FSMstate state;
enum SYSmode lpm_mode;
int flag,counter=0  ; 
char singles = 0x30 ;         //0
char tens = 0x30 ;            //0 
int Freq_Count=0 , Flag_func2=0,Flag_func1 =0  ; 
unsigned int real_freq ; 
char StrFreq [6] = { '\0'} ;
double m = -0.6 ; 
int N_ADC,N_Fout,freq_out,ADC_count=0 ;


void main(void){
  
  state = state0;  // start in idle state on RESET
  lpm_mode = mode0;     // start in idle state on RESET
  sysConfig();          // config the GPIO , Timers, ADC
  lcd_init() ;          // config the LCD
  lcd_clear() ;         // CLR the LCD
  
  while(1){
	switch(state){
	  case state0:
                enterLPM(lpm_mode);
		break;
		 
	  case state1:
		enable_interrupts();
                lcd_clear() ; 
                TIMER1_A1_config() ; 
                printFreq() ; 

		break;
		 
	  case state2:
		enable_interrupts();
                ADC_Off() ; 
                flag = 1 ; 
                state = state0;
                Timer_A0_On() ; 
                __bis_SR_register(LPM0_bits + GIE);       // Enter LPM0 w/ interrupt
                
		break;
                
                
          case state3 : 
            enable_interrupts() ; 
            lcd_clear() ; 
            lcd_home() ;
            flag=3 ;
            state=state0 ; 
            Func3() ;
            break ;
          
		
	}
  }
}
  
  
  
  
  
  