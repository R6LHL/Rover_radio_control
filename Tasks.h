#ifndef _TASKS_H
#define _TASKS_H

namespace Tasks{
	
	void checkJoystick(void);
	void printJoystick(void);
  void transmitTelemetry(void);
}

void Tasks::checkJoystick(void){
	currX = joystick.readX();
	currY = joystick.readY();
	currButton = joystick.readButton();

	OS.SetTask_(printJoystick, 0);
  OS.SetTask_(transmitTelemetry,0);
  OS.SetTask_(checkJoystick, JOYSTICK_READ_INTERVAL_MS);
}

void Tasks::printJoystick(void){
	
	Serial.print(F("Joystick X="));
	Serial.println(currX);
	
	Serial.print(F("Joystick Y="));
	Serial.println(currY);
	
	Serial.print(F("Joystick Button="));
	Serial.println(currButton);
}

void Tasks::transmitTelemetry(void)
{
#if DEBUG_MODE == ENABLED  
  Serial.print(F("Sending data...\0"));
#endif

  LoRa.beginPacket();
#if DEBUG_MODE == ENABLED  
  Serial.println(F("Sending X...\0"));
#endif
  LoRa.print(currX);
#if DEBUG_MODE == ENABLED  
  Serial.println(F("Sending Y...\0"));
#endif
  LoRa.print(currY);
#if DEBUG_MODE == ENABLED  
  Serial.println(F("Sending Button...\0"));
#endif
  LoRa.print(currButton);
#if DEBUG_MODE == ENABLED  
  Serial.println(F("End packet...\0"));
#endif
  LoRa.endPacket(async_mode);
  
#if DEBUG_MODE == ENABLED  
  Serial.println(F("Done!\0"));
  Serial.println();
#endif
}

#endif //_TASKS_H
