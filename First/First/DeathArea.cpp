#include "DeathArea.h"

DeathArea::DeathArea() : Death() {
  you = NULL;
}

DeathArea::DeathArea(Level* l, float x_,float y_,float w,float h, You* yo) : Death(l,x_,y_,w,h) {
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(255,0,0));
  shape.setSize(sf::Vector2f(width,height));
  shape.setPosition(x,y);
#endif
  you = yo;
}

#ifndef COMPILE_NO_SF
Death::render(sf::RenderWindow& window) {
  window.draw(shape);
}
#endif
