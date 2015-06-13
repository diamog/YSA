#include "stdafx.h"
#include "Collectable.h"
#include "utilities.h"

Collectable::Collectable() : Actor(){
  you = NULL;
}

Collectable::Collectable(float x_, float y_, float w, float h, You* yo) : 
  Actor(x_,y_,w,h) {
  you = yo;
}

void Collectable::act() {
  if (isRectangularHit(you,this)) {
    //level.event(eve,this);
  }
}

void Collectable::render(sf::RenderWindow& window) {
  
} 
