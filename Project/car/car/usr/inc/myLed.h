#ifndef _LED_H_
#define _LED_H_

#include"common.h"
#include"gpio.h"

enum LedInstance{
  led0,
  led1,
  led2,
  led3,
  led4,
  led5,
};

class Led{
public:
  Led();
  void on(LedInstance ledInstance);
  void off(LedInstance ledInstance);
  void turn(LedInstance ledInstance);
private:
  static uint32_t _instance[6];
  static uint32_t _pinx[6];
};



#endif  //_LED_H_