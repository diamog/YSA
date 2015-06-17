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

#ifndef COMPILE_NO_SF
void Switch::act(sf::Event& event) {
  if (isRectangularHit(you,this)) {
    level.event(eve,this);
  }
}

void Switch::render(sf::RenderWindow& window) {
  
} 
#endif
