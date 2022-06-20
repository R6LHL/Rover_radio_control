#ifndef SOFT_CONFIG_H
#define SOFT_CONFIG_H


#include <Arduino.h>
#include "compil_config.h"

typedef unsigned const char pin_number;
typedef unsigned const char interval;

unsigned const char task_queue_size = 5;

//////////////////////////////////////////////////JOYSTICK
pin_number JOYSTICK_X_AXIS_PIN = A0;
pin_number JOYSTICK_Y_AXIS_PIN = A1;
pin_number JOYSTICK_BUTTON_PIN = 4;

#ifdef USE_TC2_FOR_OS
  #ifdef DEBUG_ENABLED
    interval JOYSTICK_READ_INTERVAL = 100; //ms
  #else
    interval JOYSTICK_READ_INTERVAL = 20; //ms
  #endif //DEBUG_ENABLED
#endif

#ifdef USE_WDT_FOR_OS
  #ifdef DEBUG_ENABLED
    interval JOYSTICK_READ_INTERVAL = 8; //*16ms
  #else
    interval JOYSTICK_READ_INTERVAL = 1; //*16ms
  #endif //DEBUG_ENABLED
#endif

unsigned const int JOYSTICK_DEAD_ZONE_X = 5;
unsigned const int JOYSTICK_DEAD_ZONE_Y = 5;

//////////////////////////////////////////////////LoRa Ra-01S
pin_number _EN_NSS = 10;
pin_number _G0_DIO0 = 2;
pin_number _SCK = 13;
pin_number _MISO = 12;
pin_number _MOSI = 11;
pin_number _RST = 9;

const unsigned long frequency = 433000000;  //Hz
unsigned const char TX_Power = 20;
const bool async_mode = true;
const long signal_bandwidth = 12500;        //Hz


#endif //SOFT_CONFIG_H
