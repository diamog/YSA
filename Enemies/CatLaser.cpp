#include "stdafx.h"
#include "CatLaser.h"
#include <cmath>
#include "../Extras/utilities.h"
#include "CatBoss.h"

CatLaser::CatLaser() : Actor(),Bullet(),Death() {
}

CatLaser::CatLaser(Level* l,float x_, float y_,You* yo,CatBoss* b)
  : Actor(l,x_-10,y_-10,20,20),
    Bullet(l,x,y,width,height,"cat"), 
    Death(l,x,y,width,height,yo) {
  boss=b;
#ifndef COMPILE_NO_SF
  col=0;
  base.setSize(sf::Vector2f(width,height));
  base.setOrigin(width/2,height/2);
  base.setFillColor(sf::Color(120,120,120));
  pointer.setRadius(width/2);
  pointer.setOrigin(width/2,height/2);
  pointer.setFillColor(sf::Color(255,0,0));
  laser.setSize(sf::Vector2f(width,1));
  laser.setFillColor(sf::Color(255,0,0));
#endif
  len=.1;
  dir = 1;
  vel=2;
  rate=2;
  ticks=part=0;
}
void CatLaser::act() {
  if (y>60) {
    y-=5;
    return;
  }
  float max_rate = 100;
  if (fabs(rate)>max_rate) {
    float h = height;
    height = len;
    if (isRectangularHit(boss,this)) {
      rate=2;
      len=1;
      boss->hit();
    }
    Death::act();
    height = h;
  }
  if (rate>max_rate) {
    len+=20;
    if (len>570-(y+height/2)) {
      rate=2;
      len=1;
    }
    return;
  }
  ticks++;
  col+=rate;
  if (col>=200-rate) {
    rate*=-1;
  }
  if (col<=-rate) {
    rate*=-1;
    rate+=5;
  }
  float yx,yy;
  getObjectCenter(you,yx,yy);
  float dis = yx-(x+width/2);
  if (fabs(dis)>5)
    x+=dis/fabs(dis)*vel; 
  Death::act();
}

void CatLaser::render(sf::RenderWindow& window) {
  base.setPosition(getX1()+width/2,getY1()+height/2);
  window.draw(base);
  laser.setPosition(getX1(),getY1()+base.getSize().y);
  laser.setSize(sf::Vector2f(width,len));
  window.draw(laser);
  pointer.setFillColor(sf::Color(255,col,col));
  pointer.setPosition(getX1()+width/2,getY1()+base.getSize().y);
  window.draw(pointer);
}
