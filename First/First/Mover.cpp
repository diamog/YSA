#ifndef COMPILE_NO_VB
#include "stdafx.h"
#endif
#include "Mover.h"


Mover::Mover() : Actor() {
  lastx=lasty=0;
}

Mover::Mover(Level* l, float x_,float y_,float w,float h) : Actor(l,x_,y_,w,h) {
  lastx=lasty=0;
}

void Mover::act() {
  lastx = x;
  lasty = y;
}
