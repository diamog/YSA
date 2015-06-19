#include "stdafx.h"
#include "Death.h"
#include "utilities.h"

Death::Death() : Actor() {
  you = NULL;
}

Death::Death(Level* l, float x_,float y_,float w,float h, You* yo) : Actor(l,x_,y_,w,h) {
  you = yo;
}

#ifndef COMPILE_NO_SF
void Death::act(sf::Event& event) {
  if (isRectangularHit(you,this)) {
    you->die();
  }
}
#endif
