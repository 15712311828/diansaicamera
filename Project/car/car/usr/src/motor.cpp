#include "motor.h"
#include "gpio.h"

Motor::Motor(){
  FTM_PWM_QuickInit(MOTOR1_PWM_io, kPWM_EdgeAligned, MOTOR_HZ );
  FTM_PWM_QuickInit(MOTOR2_PWM_io, kPWM_EdgeAligned, MOTOR_HZ );
  FTM_PWM_QuickInit(MOTOR3_PWM_io, kPWM_EdgeAligned, MOTOR_HZ );
  FTM_PWM_QuickInit(MOTOR4_PWM_io, kPWM_EdgeAligned, MOTOR_HZ );
  FTM_PWM_ChangeDuty(MOTOR_FTM, MOTOR1_PWM, 0);
  FTM_PWM_ChangeDuty(MOTOR_FTM, MOTOR2_PWM, 0);
  FTM_PWM_ChangeDuty(MOTOR_FTM, MOTOR3_PWM, 0);
  FTM_PWM_ChangeDuty(MOTOR_FTM, MOTOR4_PWM, 0);
  GPIO_QuickInit(PWM_EN_INSTANCE, PWM_EN_PIN, kGPIO_Mode_OPP);
  GPIO_ResetBit(PWM_EN_INSTANCE, PWM_EN_PIN); 
}

void Motor::start(){
  GPIO_SetBit(PWM_EN_INSTANCE, PWM_EN_PIN);
}

void Motor::duty(int duty1,int duty2){
  duty1=-duty1;
  duty2=-duty2;
  if(duty1>0){
    FTM_PWM_ChangeDuty(MOTOR_FTM, MOTOR1_PWM, duty1);
    FTM_PWM_ChangeDuty(MOTOR_FTM, MOTOR2_PWM, 0);
  }
  else{
    FTM_PWM_ChangeDuty(MOTOR_FTM, MOTOR1_PWM, 0);
    FTM_PWM_ChangeDuty(MOTOR_FTM, MOTOR2_PWM, -duty1);
  }
  if(duty2>0){
    FTM_PWM_ChangeDuty(MOTOR_FTM, MOTOR3_PWM, duty2);
    FTM_PWM_ChangeDuty(MOTOR_FTM, MOTOR4_PWM, 0);
  }
  else{
    FTM_PWM_ChangeDuty(MOTOR_FTM, MOTOR3_PWM, 0);
    FTM_PWM_ChangeDuty(MOTOR_FTM, MOTOR4_PWM, -duty2);
  }
}

void Motor::stop(){
  GPIO_ResetBit(PWM_EN_INSTANCE, PWM_EN_PIN);
}