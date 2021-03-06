#include "stdafx.h"

#include "Extra.h"
#include <cstdlib>
Extra::Extra() : Collectable() {}

Extra::Extra(Level* l, float x_, float y_, float w, float h, You* yo) 
  : Collectable(l,x_,y_,w,h,yo) {
  eve = EXTRA;
#ifndef COMPILE_NO_SF
  shape.setRadius(width/2);
  shape.setFillColor(sf::Color(255,0,255));
#endif

}


#ifndef COMPILE_NO_SF
void Extra::render(sf::RenderWindow & window) {
  shape.setPosition(getX1(),getY1());
  if (!you->boss1())
    shape.setFillColor(sf::Color(180,180,180));
  else
    shape.setFillColor(sf::Color(255,0,255));
  window.draw(shape);
}
#endif
