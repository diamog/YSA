

#include "stdafx.h"
#include "Actor.h"
#include "Level.h"
Actor::Actor() {
  x=y=width=height=0;
  level = NULL;
}
Actor::Actor(Level* l, float x_,float y_,float w,float h) {
  level = l;
  x = x_;
  y = y_;
  rev=NULL;
  width = w;
  height = h;
  frame_diff=250.0/60;
}

float Actor::getX1() const {
  if (level==NULL)
    return x;
  return x-level->getX();
}
float Actor::getX2() const {return getX1()+width;}
float Actor::getY1() const {
  if (level==NULL)
    return y;
  return y-level->getY();
}
float Actor::getY2() const {return getY1()+height;}
