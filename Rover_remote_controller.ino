#include "MCU_Mega_328.hpp"
#include <LoRa.h> // API https://github.com/sandeepmistry/arduino-LoRa/blob/master/API.md
#include "Tasks.h"
#include "variables.h"
#include "TaskManager.h"

Joystick joystick(JOYSTICK_X_AXIS_PIN, JOYSTICK_Y_AXIS_PIN, 
                    JOYSTICK_BUTTON_PIN, JOYSTICK_DEAD_ZONE_X,
                      JOYSTICK_DEAD_ZONE_Y);

int currX = 0;
int currY = 0;
bool currButton = false;

////////////////////INTERRUT HANDLERS////////////
ISR(TIMER2_OVF_vect)
{
  //Serial.println("Interrupt is working");
  TaskManager::TimerTaskService_();
}
////////////////////INTERRUT HANDLERS ENDS////////////

void setup() {

  Serial.begin(9600);
  
////////SETUP TIMERS///////////////////////////////
#if DEBUG_MODE == ENABLED  
  Serial.print(F("Setup timers...\0"));
#endif
  
  TCCR2B |= (1<<CS22); // (clk/64)
  TIMSK2 |= (1<<TOIE2); // ovf interrupt enabled
  
#if DEBUG_MODE == ENABLED 
  Serial.println(F("Done!\0"));
  Serial.println();
#endif
////////SETUP TIMERS ENDS/////////////////////////

////////SETUP RADIO///////////////////////////////
#if DEBUG_MODE == ENABLED  
  Serial.print(F("Setup radio...\0"));
#endif

  if (!LoRa.begin(frequency)) 
  {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  LoRa.setSignalBandwidth(signal_bandwidth);
  
  LoRa.setTxPower(TX_Power);

#if DEBUG_MODE == ENABLED  
  Serial.println(F("Done!\0"));
  Serial.println();
#endif
////////SETUP RADIO ENDS/////////////////////////////
  
  joystick.calibrateCenter();
  Tasks::checkJoystick();
}

void loop() {
  // put your main code here, to run repeatedly:
  TaskManager::ProcessTaskQueue_();
}
