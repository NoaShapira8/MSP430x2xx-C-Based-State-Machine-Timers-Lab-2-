#ifndef _app_H_
#define _app_H_


enum FSMstate{state0,state1,state2,state3,state4}; // global variable
enum SYSmode{mode0,mode1,mode2,mode3,mode4}; // global variable

extern int flag,counter,Freq_Count,Flag_func2,Flag_func1,N_ADC,N_Fout,freq_out ; 
extern int ADC_count ; 
extern char singles,tens ; 
extern unsigned int real_freq ; 
extern char StrFreq [6] ;
extern double m ; 



#endif







