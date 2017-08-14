#ifndef _MOTOR_H_
#define _MOTOR_H_

#include"common.h"
#include"ftm.h"

#define MOTOR_HZ    (10*1000)

#define PWM_EN PTC0
#define PWM_EN_INSTANCE HW_GPIOC
#define PWM_EN_PIN 0

#define MOTOR_FTM HW_FTM0
#define MOTOR1_PWM HW_FTM_CH0
#define MOTOR2_PWM HW_FTM_CH1
#define MOTOR3_PWM HW_FTM_CH2
#define MOTOR4_PWM HW_FTM_CH3

#define MOTOR1_PWM_io FTM0_CH0_PC01
#define MOTOR2_PWM_io FTM0_CH1_PC02
#define MOTOR3_PWM_io FTM0_CH2_PC03
#define MOTOR4_PWM_io FTM0_CH3_PC04

//#define MOTOR1_PWM_io FTM0_CH3_PA06
//#define MOTOR2_PWM_io FTM0_CH4_PA07
//#define MOTOR3_PWM_io FTM0_CH5_PD05
//#define MOTOR4_PWM_io FTM0_CH6_PD06

class Motor{
public:
  Motor();
  void start();
  void duty(int duty1,int duty2);
  void stop();
};

#endif  //MOTOR
