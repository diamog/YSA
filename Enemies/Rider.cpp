#include "stdafx.h"
#include "Rider.h"
#include "../Extras/utilities.h"
#include <cmath>

Rider::Rider() : Actor(),Enemy() {
  dir=0;vel=0;
}

Rider::Rider(Level* l, float x_,float y_, You* yo, int d) 
  : Actor(l,x_,y_,70,35), Enemy(l,x_,y_,70,35,yo,1) {
  dir=d;
  vel=3;
  x1=x2=35;y2=y1=35.0/2;
#ifndef COMPILE_NO_SF
  top.setFillColor(sf::Color(75,57,30));
  rightSide.setFillColor(sf::Color(75,57,30));
  base.setFillColor(sf::Color(75,57,30));
  eye.setFillColor(sf::Color(0,0,0));
  base.setSize(sf::Vector2f(width,height/3*2));
  top.setSize(sf::Vector2f(width-height*2/3,height/3));
  rightSide.setRadius(height/3);
  eye.setRadius(height/6);
#endif
}


void Rider::act() {
  Enemy::act();
  x+=vel*dir;
}

void mod(float& val,float range) {
  while (val<0)
    val+=range;
  while(val>range)
    val-=range;
}
#ifndef COMPILE_NO_SF
void Rider::render(sf::RenderWindow& window) {
  base.setPosition(getX1(),getY1()+height/3);
  top.setPosition(getX1()+height/3,getY1());
  rightSide.setPosition(getX1()+width/2-height/3+dir*height*2/3,getY1());
  window.draw(base);
  window.draw(top);
  window.draw(rightSide);
  x1+=.5;
  x2-=.5;
  y1+=.5;
  y2-=.5;
  mod(x1,width);
  mod(x2,width);
  mod(y2,height);
  mod(y1,height);
  float y11 = getY1();
  float dx1 = height/3-x1;
  float dxx1 = x1-(width-height/3);
  if (x1<height/3) {
    if (dir==1)
      y11+=height/3;
    else
      y11+=height/3-sqrt(height*height/9-dx1*dx1);
  }
  else if (x1>width-height/3) {
    if (dir==-1)
      y11+=height/3;
    else
      y11+=height/3-sqrt(height*height/9-dxx1*dxx1);
  }
  float y21 = getY1();
  float dx2 = height/3-x2;
  float dxx2 = x2 - (width-height/3);
  if (x2<height/3) {
    if (dir==1)
      y21+=height/3;
    else
      y21+=height/3-sqrt(height*height/9-dx2*dx2);
  }
  else if (x2>width-height/3) {
    if (dir==-1)
      y21+=height/3;
    else
      y21+=height/3-sqrt(height*height/9-dxx2*dxx2);
  }
  float x11 = getX1();
  float dy1 = height/3-y1;
  if (y1<height/3) {
    if (dir==1)
      x11+=height/3;
    else
      x11+=height/3-sqrt(height*height/9-dy1*dy1);
      
  }
  float x12 = getX2();
  if (y1<height/3) {
    if (dir==-1)
      x12-=height/3;
    else
      x12-=height/3-sqrt(height*height/9-dy1*dy1);
      
  }
  float x21 = getX1();
  float dy2 = height/3-y2;
  if (y2<height/3) {
    if (dir==1)
      x21+=height/3;
    else
      x21+=height/3-sqrt(height*height/9-dy2*dy2);
  }
  float x22 = getX2();
  if (y2<height/3) {
    if (dir==-1)
      x22-=height/3;
    else
      x22-=height/3-sqrt(height*height/9-dy2*dy2);
  }
  sf::Vertex line[] =
  {
    sf::Vertex(sf::Vector2f(getX1()+x1,y11)),
    sf::Vertex(sf::Vector2f(getX1()+x1,getY2()))
  };
  window.draw(line,2,sf::Lines);
  sf::Vertex line2[] =
  {
    sf::Vertex(sf::Vector2f(getX1()+x2,y21)),
    sf::Vertex(sf::Vector2f(getX1()+x2,getY2()))
  };
  window.draw(line2,2,sf::Lines);
  sf::Vertex line3[] =
  {
    sf::Vertex(sf::Vector2f(x11,getY1()+y1)),
    sf::Vertex(sf::Vector2f(x12,getY1()+y1))
  };
  window.draw(line3,2,sf::Lines);
  sf::Vertex line4[] =
  {
    sf::Vertex(sf::Vector2f(x21,getY1()+y2)),
    sf::Vertex(sf::Vector2f(x22,getY1()+y2))
    };
  window.draw(line4,2,sf::Lines);
  
  eye.setPosition(getX1()+width/2+dir*width/4-height/6,getY1()+height/12);
  window.draw(eye);
}
#endif
void Rider::hitDetector(int adir) {
  dir*=-1;
}
