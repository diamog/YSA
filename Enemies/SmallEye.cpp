#include "stdafx.h"
#include "SmallEye.h"
#include "../Extras/utilities.h"
#include "../Level.h"
#include <cmath>
SmallEye::SmallEye() : Actor(),Enemy() {
  dir=0;vel=0;
}

SmallEye::SmallEye(Level* l, float x_,float y_, You* yo, int d) 
  : Actor(l,x_,y_,70,20), Enemy(l,x_,y_,70,20,yo,-1) {
  vel=0;
	count=0;
  dir=d;
  orig_dir=d;
  isOn=false;
  accel=.02;
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(0,0,255));
  shape.setRadius(width/2);
  shape.setScale(1,height/width);
  shape.setOrigin(width/2,height/2);
#endif
  resetx=x+width/2;
  resety=y+height/2;
}


void SmallEye::act() {
  Enemy::act();
  if (isOn) {
    vel+=accel;
    if (vel>7)
      vel=7;
  }
  else
    vel=0;
  if (dir==0)
    y-=vel;
  else if (dir==1)
    x+=vel;
  else if (dir==2)
    y+=vel;
  else if (dir==3) 
    x-=vel;
  if (isOn&&(x+width<0 || x>level->getWidth() ||y+height<0 || y>level->getHeight())) {
    reset(); 
  }
}
#ifndef COMPILE_NO_SF
void SmallEye::render(sf::RenderWindow& window) {
  shape.setPosition(getX1()+width/2,getY1()+height/4);
  window.draw(shape);
}
#endif

void SmallEye::hitDetector(int adir) {
  count++;
	if (adir==-1) {
    isOn=false;
    vel=0;
    orig_dir=dir;
    reset();
  }
  else {
    dir=adir;
    if (dir%2)
      shape.setRotation(0);
    else
      shape.setRotation(90);
    //rotate();
  }
  if (count>10)
		buildAchievement(LOOP_EYE);
}

void SmallEye::reset() {
  x=resetx-width/2;
  y=resety-height/2;  
  shape.setRotation(0);
  vel=0;
  isOn=false;
  level->resetEye();
  dir=orig_dir;
	count=0;
}
