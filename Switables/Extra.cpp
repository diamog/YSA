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
  shape.setPosition(x,y);
#endif

}


#ifndef COMPILE_NO_SF
void Extra::render(sf::RenderWindow & window) {
  window.draw(shape);
}
#endif
