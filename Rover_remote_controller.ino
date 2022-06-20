#include "MCU_Mega_168.hpp"
#include <LoRa.h> // API https://github.com/sandeepmistry/arduino-LoRa/blob/master/API.md
#include "Tasks.h"

Joystick joystick(JOYSTICK_X_AXIS_PIN, JOYSTICK_Y_AXIS_PIN, 
                    JOYSTICK_BUTTON_PIN, JOYSTICK_DEAD_ZONE_X,
                      JOYSTICK_DEAD_ZONE_Y);

int currX = 0;
int currY = 0;
bool currButton = false;

TaskManager5 OS;

////////////////////INTERRUPT HANDLERS////////////
#ifdef USE_TC2_FOR_OS
ISR(TIMER2_OVF_vect)
{
  //Serial.println("Interrupt is working");
  OS.TimerTaskService_();
}
#endif
////////////////////INTERRUPT HANDLERS ENDS////////////

void setup() {

  Serial.begin(9600);
  
////////SETUP TIMERS///////////////////////////////
#if DEBUG_MODE == ENABLED  
  Serial.print(F("Setup timers...\0"));
#endif

#ifdef USE_TC2_FOR_OS  
  MCU::TC::TC2_::SetPrescaler64();
  MCU::TC::TC2_::Ovf_Int_Enable();
  MCU::TC::TC2_::powerUp();
#endif

#ifdef USE_WDT_FOR_OS

#endif

  
  MCU::IO_::PORTB_::pullupAll();
  MCU::IO_::PORTC_::pullupAll();
  MCU::IO_::PORTD_::pullupAll();  
    
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
  OS.ProcessTaskQueue_();
}
