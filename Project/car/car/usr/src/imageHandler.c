#include "imageHandler.h"

uint8_t imgbuff[CAMERA_SIZE];
uint8_t picture[H*W];
uint8_t recoverImage[CAMERA_SIZE];
Point area[9];
Point ball;

Point::Point(){
  x=y=0;
}

Point::Point(float x,float y){
  this->x=x;
  this->y=y;
}

Point Point::operator+(const Point & rsh){
  return Point(this->x+rsh.x,this->y+rsh.y);
}

Point Point::operator-(const Point & rsh){
  return Point(this->x-rsh.x,this->y-rsh.y);
}

float Point::distance(Point & rsh){
  return sqrt((float)(this->x-rsh.x)*(this->x-rsh.x)+(this->y-rsh.y)*(this->y-rsh.y));
}

void Point::draw(){
  if(x>=0&&x<H&&y>=0&&y<W)
    color(x,y)=!color(x,y);
}

int areaGetLoc(){
  int i=0,j=0;
  int pos=0;
  while(i<H){
    int flag=1;
    if(flag&&color(i,j)==white){
      flag=0;
    }
    for(int m=0;m<pos&&flag;m++){
      if(Point(i,j).distance(area[m])<20){
        flag=0;
      }
    }
    if(flag&&(j==W-1||i==H-1||color(i,j+1)==white&&color(i+1,j)==white))
      flag=0;
    if(flag){
      int m=i;
      while(color(m,j)&&m<H&&m-i<20)m++;
      while(!color(m,j)&&m<H&&m-i<20)m++;
      while(color(m,j)&&m<H&&m-i<20)m++;
      if(m<H&&m-i<20){
        int midh=(i+m)>>1;
        int n=j;
        int k=j;
        while(!color(midh,n)&&n<W&&n-j<20)n++;
        while(!color(midh,k)&&k>=0&&j-k<20)k--;
        if(n<W&&n-j<20&&k>=0&&j-k<20){
          if(pos>=9){
            return -1;
          }
          area[pos].x=midh;
          area[pos].y=(n+k)>>1;
          pos++;
        }
      }
    }
    j++;
    if(j>=W){
      i++;
      j=0;
    }
  }
  return pos;
}

Point ballGetLoc(){
  Point res;
  int maxL=0;
  uint8_t dp[W]={0};
  for(int i=0;i<H;i++){
    for(int j=W-1;j>=0;j--){
      if(color(i,j)){
        if(j>0)
          dp[j]=dp[j-1]+1;
        else
          dp[j]=1;
        if(dp[j]>maxL&&dp[j]<20&&dp[j]>2){
          maxL=dp[j];
          res.x=i-dp[j]/2;
          res.y=j-dp[j]/2;
        }
      }
      else{
        dp[j]=0;
      }
    }
  }
  ball=res;
  if(ball.x<5&&ball.y<5||ball.x<5&&ball.y>155||
     ball.x>115&&ball.y<5||ball.x>115&&ball.y>155)
    ball=Point(60,80);
  return ball;
}

void copyImg(){
  for(int i=0;i<W*H/8;i++){
    uint8_t temp=imgbuff[i];
    for(int j=0;j<8;j++){
      picture[8*i+j]=((temp>>(7-j))&0x01);
    }
  }
}

void draw(){
  ball.draw();
  (ball+Point(1,1)).draw();
  (ball+Point(-1,1)).draw();
  (ball+Point(1,-1)).draw();
  (ball+Point(-1,-1)).draw();
  (ball+Point(2,2)).draw();
  (ball+Point(-2,2)).draw();
  (ball+Point(2,-2)).draw();
  (ball+Point(-2,-2)).draw();
}

void recoverImg(){
  for(int i=0;i<W*H/8;i++){
    uint8_t temp=0;
    for(int j=0;j<8;j++){
      temp+=picture[8*i+j]<<(7-j);
    }
    recoverImage[i]=temp;
  }
}