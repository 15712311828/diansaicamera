#ifndef _IMAGEHANDLER_H_
#define _IMAGEHANDLER_H_

#include "common.h"
#include "VCAN_camera.h"
#include "math.h"

extern uint8_t imgbuff[CAMERA_SIZE];
extern uint8_t picture[H*W];
extern uint8_t recoverImage[CAMERA_SIZE];

#define color(i,j) picture[i*W+j]
#define white 0
#define black 1

class Point{
public:
  int x,y;
  Point();
  Point(float x,float y);
  Point operator+(const Point & rsh);
  Point operator-(const Point & rsh);
  float distance(Point & rsh);
  void draw();
};

extern Point area[9];
extern Point ball;

int areaGetLoc();
Point ballGetLoc();
void copyImg();
void recoverImg();
void draw();

#endif //_IMAGEHANDLER_H_