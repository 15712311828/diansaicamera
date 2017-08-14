#include "angleControl.h"
#include "math.h"

int duty1=0;
int duty2=0;

void angleControl(float targetX,float targetY){
  static float APX=3;
  static float ADX=5;
  static float AIX=0.01;
  static float APY=3;
  static float ADY=5;
  static float AIY=0.03;

  targetX-=1690;
  targetY+=0;
  
  static float offsetIX=0;
  static float offsetIY=0;
  
  
  float offsetX=targetX-angleX;
  float AnglePX;
  if(fabs(offsetX)<300){
    AnglePX=APX;
  }
  else{
    AnglePX=APX*((fabs(offsetX)-300)/900+1);
  }
  offsetIX+=offsetX;
  float controlX=-(offsetX*AnglePX+angle_dot_x*ADX+offsetIX*AIX);
  
  float offsetY=targetY-angleY;
  float AnglePY;
  if(fabs(offsetY)<300){
    AnglePY=APY;
  }
  else{
    AnglePY=APY*((fabs(offsetY)-300)/900+1);
  }
  offsetIY+=offsetY;
  float controlY=offsetY*AnglePY+angle_dot_y*ADY+offsetIY*AIY;
  
  duty1=-controlX;//((int)controlX-(int)controlY)>>1;
  duty2=controlY;//((int)controlX+(int)controlY)>>1;
  
  if(duty1<0)
    duty1-=DEAD_VAL;
  else if(duty1>0)
    duty1+=DEAD_VAL;
  if(duty2<0)
    duty2-=DEAD_VAL;
  else if(duty2>0)
    duty2+=DEAD_VAL;
  
  if(duty1>9990)
    duty1=9990;
  else if(duty1<-9990)
    duty1=-9990;
  if(duty2>9990)
    duty2=9990;
  else if(duty2<-9990)
    duty2=-9990;
}