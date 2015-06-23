#include "stdafx.h"
#include "ColorBoss.h"
#include "../Extras/utilities.h"
#include <cmath>

ColorBoss::ColorBoss() : Enemy(), Actor() {
  vx=vy=accel=0.0f;
  r=g=b=hit_amount=0;
}

ColorBoss::ColorBoss(Level* l, float x_,float y_,float w,float h, You* yo) : Enemy(l,x_,y_,w,h,yo,16*3), Actor(l,x_,y_,w,h) {
  r=g=b=255;
  accel=.001f;
  vx=vy=0;
  hit_amount=15;
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(r,g,b));
  shape.setRadius(width/2);
#endif
}

#ifndef COMPILE_NO_SF
void ColorBoss::act(sf::Event& event) {
	x+=vx;
  y+=vy;
  Enemy::act(event);

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
	
	float adx = fabs(dx)/50000;
	float ady = fabs(dy)/50000;
	if (dx<0)
		vx+=adx;
	else
		vx-=adx;
	if (dy<0)
		vy+=ady;
	else
		vy-=ady;
	if (vx>1)
    vx=1;
	else if (vx<-1)
		vx=-1;
  if (vy>1)
    vy=1;
	else if (vy<-1)
		vy=-1;
	float accel_part = accel/fabs(dx+dy);
  return;
  if (dx+dy==0)
    return;
  
  vx -=accel_part*dx;
  vy -=accel_part*dy;
  
}

void ColorBoss::render(sf::RenderWindow& window) {
  shape.setPosition(x,y);
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
