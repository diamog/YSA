#include "stdafx.h"
#include "DeathArea.h"
#include "../Actor.h"

DeathArea::DeathArea() : Actor(),Death() { 
}

DeathArea::DeathArea(Level* l, float x_,float y_,float w,float h, You* yo) :  Actor(l,x_,y_,w,h), Death(l,x_,y_,w,h,yo) {
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(150,0,0));
  shape.setSize(sf::Vector2f(width,height));
  shape.setPosition(getX1(),getY1());
#endif
}

#ifndef COMPILE_NO_SF
void DeathArea::render(sf::RenderWindow& window) {
  shape.setSize(sf::Vector2f(width,height));
  shape.setPosition(getX1(),getY1());
  if (!you->boss1())
    shape.setFillColor(sf::Color(0,0,0));
  else
    shape.setFillColor(sf::Color(180,0,0));
  window.draw(shape);
}
#endif
