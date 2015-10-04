#include "stdafx.h"
#include "CatLaser.h"
#include <cmath>
#include "../Extras/utilities.h"
CatLaser::CatLaser() : Actor(),Bullet(),Death() {
}

CatLaser::CatLaser(Level* l,float x_, float y_,You* yo) 
  : Actor(l,x_-10,y_-10,20,20),
    Bullet(l,x,y,width,height,"cat"), 
    Death(l,x,y,width,height,yo) {

#ifndef COMPILE_NO_SF
  col=0;
  base.setSize(sf::Vector2f(width,height));
  base.setOrigin(width/2,height/2);
  base.setFillColor(sf::Color(120,120,120));
  pointer.setRadius(width/2);
  pointer.setFillColor(sf::Color(255,0,0));
  laser.setSize(sf::Vector2f(width,1));
  laser.setFillColor(sf::Color(255,0,0));
#endif
  vel=2;
  rate=2;
  ticks=part=0;
}
void CatLaser::act() {
  ticks++;
  col+=rate;
  if (col>=255-rate) {
    rate*=-1;
  }
  if (col<=-rate) {
    rate*=-1;
    rate+=2;
  }
  Death::act();
  
  
}

void CatLaser::render(sf::RenderWindow& window) {
  base.setPosition(getX1()+width/2,getY1()+height/2);
  window.draw(base);
  pointer.setPosition(getX1()+width/2,getY1()+base.getSize().y/2);
  window.draw(pointer);
  laser.setPosition(getX1(),getY1());
  window.draw(laser);
}
