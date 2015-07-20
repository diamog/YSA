#include "stdafx.h"
#include "Vine.h"
#include "utilities.h"
Vine::Vine() : Actor(),PBullet() {
}

Vine::Vine(Level* l,float x_,You* yo) 
  : Actor(l,x_,1185,20,600), PBullet(l,x_,1185,yo,-3.14159/2,NULL) {
  shape2.setFillColor(sf::Color(0,170,0));
  shape2.setSize(sf::Vector2f(width,height));
  vel=10;
  ticks=0;

}

void Vine::act() {
  ticks++;
  if (ticks>60) 
    PBullet::act();
  if(getY1()< 0)
    angle*=-1;
}


void Vine::render(sf::RenderWindow& window) {
  shape2.setPosition(getX1(),getY1());
  window.draw(shape2);
}
