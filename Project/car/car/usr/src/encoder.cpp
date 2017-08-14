#include "encoder.h"

Encoder::Encoder():speed1(0),speed2(0),dir1(0),dir2(0){
  FTM_QD_QuickInit(QEP1, kFTM_QD_NormalPolarity, kQD_CountDirectionEncoding);
  FTM_QD_QuickInit(QEP2, kFTM_QD_NormalPolarity, kQD_CountDirectionEncoding);
}

void Encoder::measure(){
  FTM_QD_GetData(HW_FTM1, &speed1, &dir1);
  FTM_QD_GetData(HW_FTM2, &speed2, &dir2);
  FTM_QD_ClearCount(HW_FTM1);
  FTM_QD_ClearCount(HW_FTM2);
}

int Encoder::getSpeed1(){
  return speed1;
}

int Encoder::getSpeed2(){
  return speed2;
}

