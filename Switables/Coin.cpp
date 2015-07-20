#include "stdafx.h"
#include "Coin.h"

Coin::Coin() : Collectable(){
}

Coin::Coin(Level* l, float x_, float y_, You* yo, EVE_CODE e) 
  : Collectable(l,x_,y_,15,15,yo) {
  eve=e;
#ifndef COMPILE_NO_SF
  shape.setRadius(width/2);
  shape.setFillColor(sf::Color(255,255,0));
#endif

}

#ifndef COMPILE_NO_SF
void Coin::render(sf::RenderWindow & window) {
  shape.setPosition(sf::Vector2f(getX1(),getY1()));
  window.draw(shape);
}
#endif
