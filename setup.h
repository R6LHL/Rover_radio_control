#ifndef _SETUP_H
#define _SETUP_H

/////////////////////////////////////
void Setup_timers(void){
	
#if DEBUG_MODE == ENABLED	
	Serial.print(F("Setup timers...\0"));
#endif
	
  TCCR2B |= (1<<CS22); // (clk/64)
  TIMSK2 |= (1<<TOIE2); // ovf interrupt enabled
  
#if DEBUG_MODE == ENABLED	
	Serial.println(F("Done!\0"));
#endif
}

#endif //_SETUP_H