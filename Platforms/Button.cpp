#include "stdafx.h"
#include "Button.h"
#include "../Enemies/Reverser.h"
#include "../Level.h"
Button::Button() : Actor(),Platform() {
  isOn=false;
}

Button::Button(Level* l, float x_,float y_,You* yo,EVE_CODE e) 
   : Actor(l,x_,y_,40,20),
     Platform(l,x_,y_,40,20,yo) {
  eve=e;
  isOn=false;
  if (eve==GREEN)
    shape.setFillColor(sf::Color(0,150,0));
  else if (eve==PURPLE)
    shape.setFillColor(sf::Color(170,0,170));
  else if (eve==ORANGE)
    shape.setFillColor(sf::Color(200,140,10));
  shape.setSize(sf::Vector2f(width,height));

}

void Button::act() {
  Platform::act();
  if (you->getPlat()==this) {
    if (!isOn) {
      level->sendEvent(eve,NULL);
      isOn=true;
    }
  }
  else
    isOn=false;
}

void Button::render(sf::RenderWindow& window) {
  shape.setPosition(getX1(),getY1());
  window.draw(shape);
}
