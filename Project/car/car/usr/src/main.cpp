#include "gpio.h"
#include "common.h"

#include "myLed.h"
#include "myUart.h"
#include "system.h"
#include "motor.h"
#include "MPU9150.h"
#include "angleCal.h"
#include "angleControl.h"
#include "VCAN_camera.h"
#include "imageHandler.h"
#include "locControl.h"
#include "speedControl.h"
#include "steer.h"

Uart uart;
Led led;
System system;
//Steer steer;

int s1=0;
int s2=0;

void interrupt(){
  static unsigned int interruptTime=0;
  
  //if(interruptTime%200==0)
  //  led.turn(led0);
  //locControl(Point(55,55));
  //speedControl(locControlOutputX,locControlOutputY);
  //angleControl(locControlOutputX,locControlOutputY);
  //angleControl(speedControlOutputX,speedControlOutputY);
  //angleControl(t1,t2);
  //steer.duty(speedControlOutputX,speedControlOutputY);
  
  interruptTime++;
}
 
int main(void)
{
  DelayInit();
  
  system.interruptCallbackInstall(interrupt);
  system.interruptStart();
  
  camera_init(imgbuff);
  
  NVIC_SetPriorityGrouping(NVIC_PriorityGroup_3);  //中断优先级分成3组
  NVIC_SetPriority(PORTC_IRQn, NVIC_EncodePriority(NVIC_PriorityGroup_3, 0, 2)); //设置PTC端口的抢占优先级的子优先级
  NVIC_SetPriority(PORTA_IRQn, NVIC_EncodePriority(NVIC_PriorityGroup_3, 0, 2));
  NVIC_SetPriority(PORTB_IRQn, NVIC_EncodePriority(NVIC_PriorityGroup_3, 0, 2));
  NVIC_SetPriority(DMA0_IRQn,  NVIC_EncodePriority(NVIC_PriorityGroup_3, 1, 2));
  NVIC_SetPriority(PIT0_IRQn,  NVIC_EncodePriority(NVIC_PriorityGroup_3, 2, 2));
  
  while(1)
  {
    camera_get_img(); 
    //uart.sendWare();
    copyImg();
    ballGetLoc();
    if(1){
      draw();
      recoverImg();
      uart.sendImage(recoverImage,CAMERA_SIZE);
    }
  }
}


