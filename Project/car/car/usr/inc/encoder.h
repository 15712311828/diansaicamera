#ifndef _MYENCODER_H_
#define _MYENCODER_H_

#include "common.h"
#include "ftm.h"
#include "lptmr.h"

#define QEP1 FTM1_QD_PHA_PA08_PHB_PA09
#define QEP2 FTM2_QD_PHA_PA10_PHB_PA11

class Encoder{
public:
  Encoder();
  void measure();
  int getSpeed1();
  int getSpeed2();
private:
  int speed1,speed2;
  uint8_t dir1,dir2;
};





#endif  //_MYENCODER_H_