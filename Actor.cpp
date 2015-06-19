

#include "stdafx.h"

#include "Actor.h"

Actor::Actor() {
  x=y=width=height=0;
  level = NULL;
}
Actor::Actor(Level* l, float x_,float y_,float w,float h) {
  level = l;
  x = x_;
  y = y_;
  width = w;
  height = h;
}
