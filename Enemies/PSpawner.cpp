#include "stdafx.h"
#include "PSpawner.h"
#include "PBullet2.h"
#include "../Extras/utilities.h"
PSpawner::PSpawner() : Actor(),PBullet() {
  bullets=NULL;
}

PSpawner::PSpawner(Level* l,float x_, float y_,You* yo, float ang,
		   std::vector<PBullet*>* b) 
  : Actor(l,x_,y_,20,20), PBullet(l,x_,y_,yo,ang,NULL) {
  bullets=b;
}

void PSpawner::act() {
  PBullet::act();
  if (getY1()<80) {
    float pi = 3.1415926535;
    int range=30;
    bullets->push_back(new PBullet2(level,x,y,you,pi/2));
    bullets->push_back(new PBullet2(level,x,y,you,pi/2+range*pi/180));
    //bullets->push_back(new PBullet(level,x,y,you,pi/2+2*range*pi/180,NULL));
    bullets->push_back(new PBullet2(level,x,y,you,pi/2-range*pi/180));
    //    bullets->push_back(new PBullet(level,x,y,you,pi/2-2*range*pi/180,NULL));
    isDead=true;
  }
}

