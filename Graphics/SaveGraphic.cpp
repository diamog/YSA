#include "stdafx.h"
#include "SaveGraphic.h"
#include "../Level.h"
SaveGraphic::SaveGraphic(Level* l,bool isC) : Actor(l,0,0,700,600) {
  alpha=255;
  mylevel=l;
#ifndef COMPILE_NO_SF
  shape.setPosition(0,0);
  shape.setSize(sf::Vector2f(700,600));
#endif
  isColor=isC;
}

#ifndef COMPILE_NO_SF
void SaveGraphic::render(sf::RenderWindow& window) {
  alpha-=10;
  if (isColor) shape.setFillColor(sf::Color(0,255,255,alpha));
  else shape.setFillColor(sf::Color(255,255,255,alpha));
  window.draw(shape);
  if (alpha<=10)
    level->sendEvent(KILL,this);
}
#endif
