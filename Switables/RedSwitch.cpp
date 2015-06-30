#include "stdafx.h"

#include "RedSwitch.h"
#include "../Extras/utilities.h"

RedSwitch::RedSwitch() : Switch(){
}

RedSwitch::RedSwitch(Level* l, float x_, float y_, float w, You* yo,EVE_CODE num) : 
  Switch(l,x_,y_,w,w,yo) {
  eve = num;
#ifndef COMPILE_NO_SF
  shape.setPosition(x,y);
  shape.setFillColor(sf::Color(255,0,0));
  shape.setSize(sf::Vector2f(width,height));
#endif
}

void RedSwitch::act() {
  Switch::act();
  //Need to hit test with Reverser
}
#ifndef COMPILE_NO_SF
void RedSwitch::render(sf::RenderWindow& window) {
  window.draw(shape);
} 
#endif
