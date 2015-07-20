#include "stdafx.h"
#include "Drone.h"
#include "../Extras/utilities.h"
#include <cmath>
Drone::Drone() : Actor(),Enemy() {
  dir=0;vel=0;
}

Drone::Drone(Level* l, float x_,float y_, You* yo, int d) 
  : Actor(l,x_,y_,35,35), Enemy(l,x_,y_,35,35,yo,1) {
  vel=3;
  while(abs(d)>3) {
    vel+=1;
    d-=(4*abs(d)/d);
  }
  if (d>=0)
    d+=1;
  if (d<0)
    d-=1;
  dir=d;
    
  angle=3.1415926535/4;
  
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(75,57,30));
  shape.setRadius(width/2);
  eye.setFillColor(sf::Color(0,0,0));
  eye.setRadius(3*width/16);
#endif
  
}


void Drone::act() {
  Enemy::act();
  
  int sign = dir/abs(dir);
  if (abs(dir)==1)
    y-=vel*sign;
  else if (abs(dir)==2)
    x+=vel*sign;
  else if (abs(dir)==3)
    y+=vel*sign;
  else
    x-=vel*sign;
}
#ifndef COMPILE_NO_SF
void Drone::render(sf::RenderWindow& window) {
  angle+=3.1415926535/60;
  shape.setPosition(getX1(),getY1());
  window.draw(shape);
  float cx,cy;
  getObjectCenter(this,cx,cy);
  float dx = cos(angle)*width/2;
  float dy = sin(angle)*width/2;
  sf::Vertex line[] =
  {
    sf::Vertex(sf::Vector2f(cx-dx,cy-dy)),
    sf::Vertex(sf::Vector2f(cx+dx,cy+dy))
  };
  window.draw(line,2,sf::Lines);
  sf::Vertex line2[] =
  {
    sf::Vertex(sf::Vector2f(cx+dx,cy-dy)),
    sf::Vertex(sf::Vector2f(cx-dx,cy+dy))
  };
  window.draw(line2,2,sf::Lines);
  
  eye.setPosition(getX1()+10*width/32,getY1()+10*height/32);
  window.draw(eye);
}
#endif
void Drone::hitDetector(int adir) {
  if (adir==-1)
    return;
  int sign = dir/abs(dir);
  dir=adir+1;
  dir%=4;
  dir+=1;
  dir*=sign;
}
