#include "config.h"
#include "setup.h"
#include <TaskManager.h>
#include "Joystick/Joystick.h"

typedef TaskManager<TASK_QUEUE_SIZE> TaskManager_;
TaskManager_ OS;

Joystick joystick(JOYSTICK_X_AXIS_PIN, JOYSTICK_Y_AXIS_PIN, 
                    JOYSTICK_BUTTON_PIN, JOYSTICK_DEAD_ZONE_X,
                      JOYSTICK_DEAD_ZONE_Y);

int currX;
int currY;
bool currButton;

#include "interrupts.h"
#include "Tasks.h"

void setup() {

  Serial.begin(9600);
  Setup_timers();
  joystick.calibrateCenter();
  Tasks::checkJoystick();
}

void loop() {
  // put your main code here, to run repeatedly:
  OS.ProcessTaskQueue_();
}
