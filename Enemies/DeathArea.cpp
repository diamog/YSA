#include "stdafx.h"
#include "DeathArea.h"
#include "../Actor.h"

DeathArea::DeathArea() : Death() { 
}

DeathArea::DeathArea(Level* l, float x_,float y_,float w,float h, You* yo) : Death(l,x_,y_,w,h,yo), Actor(l,x_,y_,w,h) {
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(255,0,0));
  shape.setSize(sf::Vector2f(width,height));
  shape.setPosition(x,y);
#endif
}

#ifndef COMPILE_NO_SF
void DeathArea::render(sf::RenderWindow& window) {
  window.draw(shape);
}
#endif
