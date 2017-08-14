#include "locControl.h"

float locControlOutputX=0;
float locControlOutputY=0;

void locControl(Point target){
  static float LP=0.17;
  static float LD=0;
  static float LI=0.001;
  static int offsetIX=0;
  static int offsetIY=0;
  
  static Point lastOffset;
  Point offset=target-ball;
  offset.y*=-1;
  offset.x*=-1;
  
  int offsetX=offset.x;
  int offsetY=offset.y;
  offsetIX+=offsetX;
  offsetIY+=offsetY;
  
  locControlOutputX=-(LP*offsetX+(offsetX-lastOffset.x)*LD+offsetIX*LI);
  locControlOutputY=-(LP*offsetY+(offsetY-lastOffset.y)*LD+offsetIY*LI);
  
  if(locControlOutputX>6)
    locControlOutputX=6;
  else if(locControlOutputX<-6)
    locControlOutputX=-6;
  if(locControlOutputY>6)
    locControlOutputY=6;
  else if(locControlOutputY<-6)
    locControlOutputY=-6;
  
  lastOffset=offset;
}