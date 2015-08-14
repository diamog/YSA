#include "stdafx.h"
#include "Cloud.h"
#include "../Extras/utilities.h"
#include <cmath>
Cloud::Cloud() : Actor(),Enemy() {

}

Cloud::Cloud(Level* l, float x_,float y_, You* yo,SmallEye* e,
	     std::vector<CBullet*>* b) 
  : Actor(l,x_,y_,40,40), Enemy(l,x_,y_,40,40,yo,1) {
  eye=e;
  ticks=0;
  rate=1;
  max_tick=90;
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(255,255,255));
  shape.setRadius(width/2);
#endif
  bullets = b;
  isDead=false;
}


void Cloud::act() {
  
  Enemy::act();
  ticks+=rate;
  if (ticks>=max_tick) {
    bullets->push_back(new CBullet(level,x+width/2,y+height,you,eye));
    ticks=0;
  }
  for (size_t i=0;i<bullets->size();i++) {
    if (!(*bullets)[i]->isGone() &&
	isRectangularHit((*bullets)[i],this)&&(*bullets)[i]->getVal()<0) {
      isDead=true;
      (*bullets)[i]->setDead();
    }
  }
  if (isDead&&you->getDifficulty()>=HARD) {
    for (size_t i=0;i<bullets->size();i++) {
      if ((*bullets)[i]->getVal()<0) {
	(*bullets)[i]->setDead();
      }
    }
  }
}

#ifndef COMPILE_NO_SF
void Cloud::render(sf::RenderWindow& window) {
  int col = 255-ticks*1.0/max_tick*180;
  shape.setFillColor(sf::Color(col,col,col));
  shape.setPosition(getX1(),getY1());
  window.draw(shape);
}
#endif
