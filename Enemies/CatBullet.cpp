#include "stdafx.h"
#include "CatBullet.h"
#include "../Extras/utilities.h"
CatBullet::CatBullet() : Actor(),Bullet(),Death() {
  angle=0;
  vel=0;
  isDead=true;
}

CatBullet::CatBullet(Level* l,float x_, float y_,float rad,You* yo, 
                 std::vector<ThinPlat*>* p) 
  : Actor(l,x_-rad,y_-rad,rad*2,rad*2),
    Bullet(l,x_-rad,y_-rad,rad*2,rad*2,"cat"), 
    Death(l,x_-rad,y_-rad,rad*2,rad*2,yo) {
  angle=getRand(0,getPI()*2);
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(170,0,170));
  num_circ = 6;
  vel=5;
  for (int i=num_circ-1;i>0;i--) {
    track[i].setRadius(width/2);
    track[i].setFillColor(sf::Color(170,0,170,(num_circ-i)*255/(num_circ)));
    track[i].setPosition(getX1(),getY1());
    x+=cos(angle)*vel;
    y+=sin(angle)*vel;
  }
  track[0].setRadius(width/2);
  track[0].setPosition(x,y);
  track[0].setFillColor(sf::Color(170,0,170));
#endif
  isDead=false;
  plats=p;
  tick=0;
}
float getIncidentAngle(float angle) {
  if (angle<getPI()/2) return angle;
  else if (angle<3*getPI()/2) return fabs(getPI()-angle);
  else return getPI()*2-angle;
}
float getComplement(float angle) {
  return getPI()/2-getIncidentAngle(angle); 
}
void CatBullet::act() {
  x+=cos(angle)*vel;
  y+=sin(angle)*vel;
  Death::act();
  tick++;
  if (x<0) {
    x=0;
    angle=2*getPI()+getIncidentAngle(angle)*(2*(angle<getPI())-1);
  }
  else if (x>700-width) {
    x=700-width;
    angle=getPI()-getIncidentAngle(angle)*(2*(angle<getPI())-1);
  }
  else if (y<0) {
    y=0;
    angle=getPI()/2+getComplement(angle)*(2*(angle<3*getPI()/2)-1);
  }
  else if (y>570-height) {
    y=570-height;
    angle=3*getPI()/2+getComplement(angle)*(2*(angle<getPI()/2)-1);
  }
  while (angle<0) angle+=2*getPI();
  while (angle>2*getPI()) angle-=2*getPI();
  if (tick>7*30) {
    isDead=true;
    if (plats!=NULL)
      plats->push_back(new ThinPlat(level,x,y+height/2,width,you));
  }
}

void CatBullet::render(sf::RenderWindow& window) {
  for (int i=num_circ-1;i>0;i--) {
    sf::Vector2f pos = track[i-1].getPosition();
    track[i].setPosition(pos.x,pos.y);
    window.draw(track[i]);
  }
  track[0].setPosition(getX1(),getY1());
  window.draw(track[0]);
}
