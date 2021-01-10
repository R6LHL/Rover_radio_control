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
  Serial.println();
#endif
}

void Setup_radio(void){

#if DEBUG_MODE == ENABLED  
  Serial.print(F("Setup radio...\0"));
#endif

  if (!LoRa.begin(frequency)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  LoRa.setSignalBandwidth(signal_bandwidth);
  
  LoRa.setTxPower(TX_Power);

#if DEBUG_MODE == ENABLED  
  Serial.println(F("Done!\0"));
  Serial.println();
#endif
}

#endif //_SETUP_H
