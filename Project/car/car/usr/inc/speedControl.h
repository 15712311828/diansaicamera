#ifndef _SPEED_CONTROL_
#define _SPEED_CONTROL_

#include "imageHandler.h"

extern int speedX;
extern int speedY;
extern float speedControlOutputX;
extern float speedControlOutputY;

void speedControl(int targetX,int targetY);

#endif //_SPEED_CONTROL_