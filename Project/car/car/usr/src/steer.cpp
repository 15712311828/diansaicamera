#include "steer.h"
#include "ftm.h"

Steer::Steer(){
  FTM_PWM_QuickInit(STEERX_PWM_io, kPWM_EdgeAligned, STEER_HZ );
  FTM_PWM_QuickInit(STEERY_PWM_io, kPWM_EdgeAligned, STEER_HZ );
  FTM_PWM_ChangeDuty(STEER_FTM, STEERX_PWM, 0);
  FTM_PWM_ChangeDuty(STEER_FTM, STEERY_PWM, 0);
}

void Steer::duty(int duty1,int duty2){
  static int lastDuty1=0;
  static int lastDuty2=0;
  if(duty1>400)
    duty1=400;
  else if(duty1<-400)
    duty1=-400;
  if(duty2>400)
    duty2=400;
  else if(duty2<-400)
    duty2=-400;
  if(duty1-lastDuty1>50){
    duty1=lastDuty1+50;
  }
  else if(duty1-lastDuty1<-50){
    duty1=lastDuty1-50;
  }
  if(duty2-lastDuty2>50){
    duty2=lastDuty2+50;
  }
  else if(duty2-lastDuty2<-50){
    duty2=lastDuty2-50;
  }
  lastDuty1=duty1;
  lastDuty2=duty2;
  duty1+=3600;
  duty2+=4200;
  FTM_PWM_ChangeDuty(STEER_FTM, STEERX_PWM, duty1);
  FTM_PWM_ChangeDuty(STEER_FTM, STEERY_PWM, duty2);
  
}