#include "stdafx.h"
#include "CBullet.h"
#include "../Extras/utilities.h"
CBullet::CBullet() : Actor(),Bullet(),Death() {
  vel=0;
  isDead=true;
}

CBullet::CBullet(Level* l,float x_, float y_,You* yo,SmallEye* e) 
  : Actor(l,x_,y_,15,50),
    Bullet(l,x_,y_,15,50,"cloud"), 
    Death(l,x_,y_,15,50,yo) {
  x-=width/2;
  eye=e;
  dir=1;
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(0,220,220));
  shape.setRadius(1);
  shape.setScale(width/2,height/2);
#endif
  vel=4;
  isDead=false;
}

void CBullet::act() {

  y+=dir*vel;
  Death::act();
  if (getX1()>700||getX2()<0||getY1()>600||getY2()<0)
    isDead=true;
  if (eye&&isRectangularHit(this,eye))  {
    dir=-1;
    vel=5;
  }
}

