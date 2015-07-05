#include "stdafx.h"
#include "ColorBoss.h"
#include "../Extras/utilities.h"
#include <cmath>
#include "../Level.h"
ColorBoss::ColorBoss() : Actor(),Enemy() {
  vx=vy=accel=0.0f;
  r=g=b=hit_amount=0;
}

ColorBoss::ColorBoss(Level* l, float x_,float y_,float w,float h, You* yo) : 
  Actor(l,x_,y_,w,h), Enemy(l,x_,y_,w,h,yo,16*3) {
  r=g=b=255;
  accel=.001f*frame_diff*frame_diff;
  vx=vy=0;
  hit_amount=20;
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(r,g,b));
  shape.setRadius(width/2);
#endif
  hasMessaged=false;
}

void ColorBoss::act() {
  x+=vx;
  y+=vy;
  if (getX2()<640&&getY1()>30&&!hasMessaged) {
    level->sendEvent(MISCE_2,NULL);
    hasMessaged=true;
  }
  Enemy::act();

  //check if hit by color bullets
  for (unsigned int i=0;i<you->getBullets().size();i++) {
    if (isRectangularHit(this,you->getBullets()[i])) {
      if (you->getBullets()[i]->getType()=="red")
        color_hit(r);
      else if (you->getBullets()[i]->getType()=="green")
        color_hit(g);
      else if (you->getBullets()[i]->getType()=="blue")
        color_hit(b);
      else
        continue;
      you->removeBullet(i);
      i--;      
    }
  }
  float youx,youy;
  getObjectCenter(you,youx,youy);
  float centerx,centery;
  getObjectCenter(this,centerx,centery);
        
  float dx = centerx-youx;
  float dy = centery-youy;
  if (fabs(dx)<5)
    dx=0;
  if (fabs(dy)<5)
    dy=0;
  
  float adx = fabs(dx)/50000*frame_diff*frame_diff;
  float ady = fabs(dy)/50000*frame_diff*frame_diff;
  float damp = .005*frame_diff;
  if (dx<0)
    vx+=adx+(vx<0)*damp;
  else
    vx-=adx+(vx>0)*damp;
  if (dy<0)
    vy+=ady+(vy<0)*damp;
  else
    vy-=ady+(vy>0)*damp;
  float limit=.8*frame_diff;
  if (vx>limit)
    vx=limit;
  else if (vx<-limit)
    vx=-limit;
  if (vy>limit)
    vy=limit;
  else if (vy<-limit)
    vy=-limit;
  float accel_part = accel/fabs(dx+dy);
  return;
  if (dx+dy==0)
    return;
  
  vx -=accel_part*dx;
  vy -=accel_part*dy;
  
}
#ifndef COMPILE_NO_SF
void ColorBoss::render(sf::RenderWindow& window) {
	
  float cx,cy;
  getObjectCenter(this,cx,cy);
  float mag = sqrt(vx*vx+vy*vy);
  float angle = atan2(vy,vx);
  float x2 = cx-mag*cos(angle);
  float y2 = cy-mag*sin(angle);
  sf::Vertex line[] =
  {
    sf::Vertex(sf::Vector2f(cx, cy)),
    sf::Vertex(sf::Vector2f(x2, y2))
  };

  window.draw(line, 2, sf::Lines);
  shape.setPosition(getX1(),getY1());
  window.draw(shape);
}
#endif

void ColorBoss::hit() {
  r-=hit_amount/3;
  g-=hit_amount/3;
  b-=hit_amount/3;
  if (r<0)
    r=0;
  if (g<0)
    g=0;
  if (b<0)
    b=0;
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(r,g,b));
#endif
}
void ColorBoss::color_hit(int& color) {
  color-=hit_amount;
  if (color<0)
    color=0;
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(r,g,b));
#endif
}
