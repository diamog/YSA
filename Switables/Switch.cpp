#include "stdafx.h"

#include "Switch.h"
#include "../Extras/utilities.h"
#include "../Level.h"

Switch::Switch() : Actor(){
  you = NULL;
}

Switch::Switch(Level* l, float x_, float y_, float w, float h, You* yo) : 
  Actor(l,x_,y_,w,h) {
  you = yo;
}

void Switch::act() {
  if (isRectangularHit(you,this)) {
    level->sendEvent(eve,this);
  }
}
