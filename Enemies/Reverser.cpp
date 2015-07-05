#include "stdafx.h"
#include "Reverser.h"
#include "../Level.h"

Reverser::Reverser() : Actor(),Death(), You() {
  isVertMirror=true;
}

Reverser::Reverser(Level* l, You* yo, bool isVMirror) : 
  Actor(l,yo->getX1(),yo->getY1(),20,20), Death(l,0,0,20,20,yo), 
  You(0,0,20,20,NULL) {
  isVertMirror = isVMirror;
  if (isVMirror) {
    x=700-x-width;
    dx*=-1;
  }
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(100,100,0));
#endif
}

void Reverser::act() {
  You::act();
  Death::act();
  if (x<0)
    x=0;
  else if (x+width>level->getWidth())
    x=level->getWidth()-width;
  if (y<0)
    y=0;
  else if (y+height>level->getHeight())
    y = level->getHeight()-height;
}


#ifndef COMPILE_NO_SF
void Reverser::render(sf::RenderWindow& window) {
  shape.setPosition(getX1(),getY1());
  shape.setFillColor(sf::Color(180,180,0,alpha));
  window.draw(shape);

}
#endif
