#include "stdafx.h"
#include "PGhost.h"
#include "PBullet2.h"
#include "../Extras/utilities.h"
#include "../Level.h"
PGhost::PGhost() : Actor(), Enemy() {
}

PGhost::PGhost(Level* l, bool isLeft, You* yo,std::vector<PBullet*>* b) : 
  Actor(l,0,630,70,50), Enemy(l,0,630,70,50,yo,1000) {
  bullets=b;
  if (isLeft)
    x=150;
  else
    x=700-150-70;
#ifndef COMPILE_NO_SF
  texture = getGraphic("GhostPumpkin");
#endif
  ticks=0;
}

void PGhost::act() {
  Enemy::act();
  ticks++;
  if (ticks>60) {
    ticks=0;
    float yx,yy;
    getObjectCenter(you,yx,yy);
    yy+=level->getY();
    float shotx = x+width/2;
    float shoty = y+height/2+height/6;
    float angle = atan2(yy-shoty,yx-shotx);
    bullets->push_back(new PBullet2(level,shotx,shoty,you,angle));
  }
}

#ifndef COMPILE_NO_SF
void PGhost::render(sf::RenderWindow& window) {  
  head.setTexture(texture);
  head.setPosition(getX1(),getY1());
  window.draw(head);
  
}
#endif
