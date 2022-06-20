#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "compil_config.h"
#include "soft_config.h"
#include "TaskManager.h"
#include "Joystick.h"

extern Joystick joystick;

extern int currX;
extern int currY;
extern bool currButton;
typedef TaskManager<task_queue_size> TaskManager5;
extern TaskManager5 OS;

#endif //_VARIABLES_H_
