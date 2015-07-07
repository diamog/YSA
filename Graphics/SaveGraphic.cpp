#include "SaveGraphic.h"
#include "../Level.h"
SaveGraphic::SaveGraphic(Level* l) : Actor(l,0,0,700,600) {
  alpha=255;
  mylevel=l;
#ifndef COMPILE_NO_SF
  shape.setPosition(0,0);
  shape.setSize(sf::Vector2f(700,600));
#endif
}

#ifndef COMPILE_NO_SF
void SaveGraphic::render(sf::RenderWindow& window) {
  alpha-=10;
  shape.setFillColor(sf::Color(0,255,255,alpha));
  window.draw(shape);
  if (alpha<=10)
    level->sendEvent(KILL,this);
}
#endif
