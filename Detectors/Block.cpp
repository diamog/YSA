#include "stdafx.h"
#include "Block.h"
#include "../Extras/utilities.h"
#include "../Level.h"
#include <cmath>
Block::Block() : Actor(),BigEye(),Platform() {}
float getTargetAngle(int dir) {
  if (dir==0)
    return 270;
  else if (dir==1)
    return 0;
  else if (dir==2)
    return 90;
  else
    return 180;
}
float getDir(float ang1,float target) {
  if (target>ang1) {
    if (target-ang1>180)
      return -1;
    return 1;
  }
  else {
    if (ang1-target>180)
      return 1;
    return -1;
  }
}
Block::Block(Level* l, float x_,float y_,int blockType, 
	     SmallEye* e,You* yo, int d) : 
  Actor(l,x_,y_,80,80), BigEye(l,x_,y_,NOTHING,e), Platform(l,x_,y_,80,80,yo){
  dir = d;
  if (blockType==0)
    shape.setFillColor(sf::Color(170,0,170));
  else if (blockType==1)
    shape.setFillColor(sf::Color(0,150,0));
  shape.setSize(sf::Vector2f(width,height));
  int amm=6;
  float size = (amm-1)/2*width/amm;
  angle=getTargetAngle(dir);
  arrow.setRadius(size);
  arrow.setPointCount(3);
  arrow.setOrigin(size,size);
  arrow.setFillColor(sf::Color(180,180,180));
}

bool Block::isInside() {
  float ex,ey;
  float cx,cy;
  getObjectCenter(this,cx,cy);
  getObjectCenter(eye,ex,ey);
  return (sqrt(pow(cx-ex,2)+pow(cy-ey,2))<8);

}
void Block::act() {
  if (fabs(angle-getTargetAngle(dir))<8) {
    angle=getTargetAngle(dir);
  }
  else if (getTargetAngle(dir)==0&&fabs(angle-360)<8)
    angle=0;
  else 
    angle+=8*getDir(angle,getTargetAngle(dir));
  if (angle<0)
    angle+=360;
  Platform::act();
  BigEye::act();
}
#ifndef COMPILE_NO_SF
void Block::render(sf::RenderWindow& window) {
  shape.setPosition(getX1(),getY1());
  window.draw(shape);
  arrow.setRotation(angle);
  arrow.setPosition(getX1()+width/2,getY1()+height/2);
  window.draw(arrow);
   
  //DRAW ARROW
  
}
#endif
