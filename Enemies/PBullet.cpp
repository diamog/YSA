#include "stdafx.h"
#include "PBullet.h"
#include "utilities.h"
PBullet::PBullet() : Actor(),Bullet(),Death() {
  angle=0;
  vel=0;
  isDead=true;
}

PBullet::PBullet(Level* l,float x_, float y_,You* yo, float ang, 
                 std::vector<Stem*>* s) 
  : Actor(l,x_,y_,7,7),
    Bullet(l,x_,y_,7,7,"pumpkin"), 
    Death(l,x_,y_,7,7,yo) {
  angle=ang;
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(140,0,0));
#endif
  vel=6;
  isDead=false;
  stems=s;
}

void PBullet::act() {
  x+=cos(angle)*vel;
  y+=sin(angle)*vel;
  Death::act();
  if (getX1()>700||getX2()<0||getY1()>600||getY2()<0)
    isDead=true;
  if (stems!=NULL) {
    for (unsigned int i=0;i<stems->size();i++) {
      if (isRectangularHit(this,(*stems)[i])) {
	(*stems)[i]->setDeath();
      }
    }
  }
}

