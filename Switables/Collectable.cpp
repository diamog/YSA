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

#ifndef COMPILE_NO_SF
void Collectable::act(sf::Event& event) {
  if (isRectangularHit(you,this)) {
    activate();
    level->sendEvent(eve,this);
  }
}

void Collectable::render(sf::RenderWindow& window) {
  
} 
#endif
