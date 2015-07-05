#include "stdafx.h"

#include "RedSwitch.h"
#include "../Extras/utilities.h"

RedSwitch::RedSwitch() : Switch(){
}

RedSwitch::RedSwitch(Level* l, float x_, float y_, float w, You* yo,EVE_CODE num) : 
  Switch(l,x_,y_,w,w,yo) {
  eve = num;
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(255,0,0));
  shape.setSize(sf::Vector2f(width,height));
#endif
}

void RedSwitch::act() {
  Switch::act();
}

void RedSwitch::activate() {
#ifndef COMPILE_NO_SF
  if (eve==RED_1) 
    shape.setFillColor(sf::Color(0,255,0));
  else if (eve==RED_2)
    shape.setFillColor(sf::Color(0,0,255));
  else if (eve==RED_3)
    shape.setFillColor(sf::Color(255,255,255));
  else if (eve==RED_4)
    shape.setFillColor(sf::Color(0,0,0));
  else if (eve==RED_5)
    shape.setFillColor(sf::Color(0,255,255));
#endif
}
#ifndef COMPILE_NO_SF
void RedSwitch::render(sf::RenderWindow& window) {
  shape.setPosition(getX1(),getY1());
  window.draw(shape);
  shape.setFillColor(sf::Color(255,0,0));
} 
#endif
