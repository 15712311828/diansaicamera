#include "speedControl.h"
#include "math.h"


int speedX=0;
int speedY=0;
float speedControlOutputX=0;
float speedControlOutputY=0;

void speedControl(int targetX,int targetY){
  static Point ballQueue[15];
  static int pos=0;
  static Point speed;
  
  if(ballQueue[pos].x!=0||ballQueue[pos].y!=0)
    speed=ball-ballQueue[pos];
  ballQueue[pos]=ball;
  pos++;
  if(pos>=15){
    pos=0;
  }
  
  static int SPX=50;
  static int SDX=0;
  static int SPY=50;
  static int SDY=0;
  
  int offsetX=targetX-speed.x;
  int offsetY=targetY-speed.y;
  
  int speedPX=SPX;
  if(abs((float)offsetX)>4){
    speedPX*=(abs((float)offsetX)-4)/8+1;
  }
  int speedPY=SPY;
  if(abs((float)offsetY)>4){
    speedPY*=(abs((float)offsetY)-4)/8+1;
  }
  
  speedControlOutputX=offsetX*speedPX;
  speedControlOutputY=-offsetY*speedPY;
  
  if(speedControlOutputX>1400)
    speedControlOutputX=1400;
  else if(speedControlOutputX<-1400)
    speedControlOutputX=-1400;
  if(speedControlOutputY>1400)
    speedControlOutputY=1400;
  else if(speedControlOutputY<-1400)
    speedControlOutputY=-1400;
}