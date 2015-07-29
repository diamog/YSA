#include "stdafx.h"
#include "ColorRemove.h"
#include "../Level.h"
ColorRemove::ColorRemove(Level* l,sf::Color col, float x_, float y_) : 
  Actor(l,x_,y_,0,0) {
  rad=1;
  mylevel=l;
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(0,0,0,0));
  shape.setOutlineColor(col);
  shape.setOutlineThickness(25);
#endif
}

#ifndef COMPILE_NO_SF
void ColorRemove::render(sf::RenderWindow& window) {
  shape.setOrigin(rad,rad);
  shape.setPosition(x,y);
  shape.setRadius(rad);
  window.draw(shape);
}
#endif
