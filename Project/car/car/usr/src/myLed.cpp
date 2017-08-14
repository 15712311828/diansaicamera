#include"myLed.h"

#define HW_GPIO_NULL 0xFF

Led::Led(){
  for(int i=0;i<6;i++){
    if(_instance[i]!=HW_GPIO_NULL){
      GPIO_QuickInit(_instance[i],_pinx[i],kGPIO_Mode_OPP);
      GPIO_SetBit(_instance[i],_pinx[i]);
    }
  }
}

void Led::on(LedInstance ledInstance){
  GPIO_ResetBit(_instance[ledInstance],_pinx[ledInstance]);
}

void Led::off(LedInstance ledInstance){
  GPIO_SetBit(_instance[ledInstance],_pinx[ledInstance]);
}

void Led::turn(LedInstance ledInstance){
  GPIO_ToggleBit(_instance[ledInstance],_pinx[ledInstance]);
}

uint32_t Led::_instance[6]={
  HW_GPIO_NULL,
  HW_GPIO_NULL,
  HW_GPIO_NULL,
  HW_GPIO_NULL,
  HW_GPIO_NULL,
  HW_GPIO_NULL
};

uint32_t Led::_pinx[6]={
  9,
  17,
  22,
  23,
  NULL,
  NULL
};
