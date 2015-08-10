#include "stdafx.h"
#include "Collectable.h"
#include "../Extras/utilities.h"
#include "../Level.h"

Collectable::Collectable() : Actor(){
  you = NULL;
}

Collectable::Collectable(Level* l, float x_, float y_, float w, float h, You* yo) : 
  Actor(l,x_,y_,w,h) {
  you = yo;
}

void Collectable::act() {
  if (you->getDead())
    return;
  if (isRectangularHit(you,this)) {
    activate();
    level->sendEvent(eve,this);
  }
}
