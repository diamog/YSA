#ifndef COMPILE_NO_VB
#include "stdafx.h"
#endif
#include "Switch.h"
#include "utilities.h"

Switch::Switch() : Actor(){
  you = NULL;
}

Switch::Switch(Level* l, float x_, float y_, float w, float h, You* yo) : 
  Actor(l,x_,y_,w,h) {
  you = yo;
}

void Switch::act() {
  if (isRectangularHit(you,this)) {
    level.event(eve,this);
  }
}

#ifndef COMPILE_NO_SF
void Switch::render(sf::RenderWindow& window) {
  
} 
#endif
