#include "stdafx.h"
#include "Reverser.h"

Reverser::Reverser() : Enemy(), You() {
  isVertMirror=true;
}

Reverser::Reverser(Level* l, You* yo, bool isVMirror) : Enemy(l,0,0,20,20,yo,3),
		   Actor(l,yo->getX1(),yo->getY1(),20,20), You(0,0,20,20,NULL) {
  isVertMirror = isVMirror;
  if (isVMirror)
    dx*=-1;
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(100,100,0));
#endif
}


#ifndef COMPILE_NO_SF
void Reverser::render(sf::RenderWindow& window) {
  
}
#endif
