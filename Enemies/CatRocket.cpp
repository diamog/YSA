#include "stdafx.h"
#include "CatRocket.h"
#include <cmath>
#include "../Extras/utilities.h"
CatRocket::CatRocket() : Actor(),Bullet(),Death() {
}

CatRocket::CatRocket(Level* l,float x_, float y_,int index, int max,You* yo) 
  : Actor(l,x_-10,y_-10,20,20),
    Bullet(l,x,y,width,height,"cat"), 
    Death(l,x,y,width,height,yo) {

#ifndef COMPILE_NO_SF
  int col = 80;
  base.setSize(sf::Vector2f(width,height));
  base.setOrigin(width/2,height/2);
  base.setFillColor(sf::Color(col,0,col));
  shape.setRadius(width/2);
  shape.setOrigin(width/2,height/2);
  shape.setFillColor(sf::Color(col,0,col));
#endif
  isDead=false;
  ticks=part=0;
  float d = 700/2.0-40;
  float y2 = 300;
  float dx = d/max;
  float x2 = x + dx*index;
  float part1_ticks = 50;
  if (index==0) {
    a=b=c=0;
    rate = (y2-y)/part1_ticks;
  }
  else {
    a = (y2-y)/(x2*x2-2*x*x2+x*x);
    b = -2*a*x;
    c = y + a*x*x;
    rate = (x2-x)/part1_ticks;
  }
}
void CatRocket::act() {
  if (part==0) {
    if (a==0) {
      y+=rate;
    }
    else {
      x+=rate;
      y=a*x*x+b*x+c;
    }
    if (fabs(y-300)<5)
      part=1;
  }
  else if (part==1) {
    y-=6;
    if (y+height<=-height) {
      part=2;
      shape.setFillColor(sf::Color(170,0,170));
      base.setFillColor(sf::Color(170,0,170));
    }
  }
  else if (part==2) {
    y+=7;
    if (y>600)
      isDead=true;
    Death::act();
  }

  
}

void CatRocket::render(sf::RenderWindow& window) {
  base.setPosition(getX1()+width/2,getY1()+height/2);
  window.draw(base);
  shape.setPosition(getX1()+width/2,getY1());
  if (part==2) 
    shape.setPosition(getX1()+width/2,getY2());
  window.draw(shape);
}
