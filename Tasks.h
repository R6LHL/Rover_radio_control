#ifndef _TASKS_H
#define _TASKS_H

namespace Tasks{
	
	void checkJoystick(void);
	void printJoystick(void);
}

void Tasks::checkJoystick(void){
	currX = joystick.readX();
	currY = joystick.readY();
	currButton = joystick.readButton();
	
	OS.SetTask_(checkJoystick, JOYSTICK_READ_INTERVAL_MS);
	OS.SetTask_(printJoystick, JOYSTICK_READ_INTERVAL_MS);
}

void Tasks::printJoystick(void){
	
	Serial.print(F("Joystick X="));
	Serial.println(currX);
	
	Serial.print(F("Joystick Y="));
	Serial.println(currY);
	
	Serial.print(F("Joystick Button="));
	Serial.println(currButton);
  Serial.println();
}

#endif //_TASKS_H
