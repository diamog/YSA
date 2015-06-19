#include "ColorBoss.h"
#include "utilities.h"

ColorBoss::ColorBoss() : Enemy() {
  vx=vy=accel=r=g=b=hit_amount=0;
}

ColorBoss::ColorBoss(Level* l, float x_,float y_,float w,float h, You* yo) : Enemy(l,x_,y_,w,h,yo,16*3) {
  r=g=b=255;
  accel=.1;
  vx=vy=0;
  hit_amount=15;
}

#ifndef COMPILE_NO_SF
ColorBoss::act(sf::Event& event) {

  x+=vx;
  y+=vy;
  Enemy::act(event);
  //check if hit by color bullets
  for (unsigned int i=0;i<you->getBullets().size();i++) {
    if (isRectangularHit(this,you->getBullets()[i])) {
      if (you->getBullet()[i]->getType()=="red")
	color_hit(r);
      else if (you->getBullet()[i]->getType()=="green")
	color_hit(g);
      else if (you->getBullet()[i]->getType()=="blue")
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
  if (dx<5)
    dx=0;
  if (dy<5)
    dy=0;
  if (dx+dy==0)
    return;
  float accel_part = accel/(dx+dy);
  vx +=accel_part*dx;
  vy +=accel_part*dy;

}

void ColorBoss::render(sf::RenderWindow& window) {

}
#endif

void ColorBoss::hit() {
  r-=hit_amount/3;
  g-=hit_amount/3;
  b-=hit_amount/3;
}
void ColorBoss::color_hit(int& color) {
  color-=hit_amount;
}
