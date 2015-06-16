#ifndef COMPILE_NO_VB
#include "stdafx.h"
#endif
#include "Collectable.h"
#include "utilities.h"

Collectable::Collectable() : Actor(){
  you = NULL;
}

Collectable::Collectable(Level* l, float x_, float y_, float w, float h, You* yo) : 
  Actor(l,x_,y_,w,h) {
  you = yo;
}

void Collectable::act() {
  if (isRectangularHit(you,this)) {
    //level.event(eve,this);
  }
}

#ifndef COMPILE_NO_SF
void Collectable::render(sf::RenderWindow& window) {
  
} 
#endif
