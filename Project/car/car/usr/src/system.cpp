#include"system.h"

System::System(){
  PIT_InitTypeDef PIT_InitStruct1;
  PIT_InitStruct1.chl = HW_PIT_CH0;
  PIT_InitStruct1.timeInUs = 10*1000;
  PIT_Init(&PIT_InitStruct1);
}

void System::interruptCallbackInstall(PIT_CallBackType callback){
  PIT_CallbackInstall(HW_PIT_CH0, callback);
}

void System::interruptStart(){
  PIT_ITDMAConfig(HW_PIT_CH0, kPIT_IT_TOF, true);
}