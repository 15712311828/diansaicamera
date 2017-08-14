#ifndef _STEER_H_
#define _STEER_H_

#define STEER_HZ    (333)

#define STEER_FTM HW_FTM2
#define STEERX_PWM HW_FTM_CH0
#define STEERY_PWM HW_FTM_CH1

#define STEERX_PWM_io FTM2_CH0_PB18
#define STEERY_PWM_io FTM2_CH1_PB19

class Steer{
public:
  Steer();
  void duty(int duty1,int duty2);
};



#endif