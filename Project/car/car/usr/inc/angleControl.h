#ifndef _ANGLE_CONTROL_H_
#define _ANGLE_CONTROL_H_

#include "angleCal.h"

#define DEAD_VAL 800

extern int duty1;
extern int duty2;

void angleControl(float targetX,float targetY);

#endif //_ANGLE_CONTROL_H_