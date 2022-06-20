#ifndef _TASKS_H
#define _TASKS_H

#include <Arduino.h>
#include "variables.h"
#include <LoRa.h> // API https://github.com/sandeepmistry/arduino-LoRa/blob/master/API.md

namespace Tasks{
	
	void checkJoystick(void);
	void printJoystick(void);
  void transmitTelemetry(void);
}

#endif //_TASKS_H
