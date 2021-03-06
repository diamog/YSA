#include "stdafx.h"
#include "Pumpkin.h"
#include "PSpawner.h"
#include "PBullet2.h"
#include "../Extras/utilities.h"
#include "../Level.h"
#include "Vine.h"
#include "WallVine.h"
#include <cmath>
Pumpkin::Pumpkin() : Actor(),Enemy() {
  ticks=0;part=-1;
}

Pumpkin::Pumpkin(Level* l, You* yo) 
  : Actor(l,120,870,500,300), Enemy(l,120,870,500,300,yo,5) {
  ticks=0;
  r=0;
  dir=1;
  part=-1;
  ghostL=NULL;
  ghostR=NULL;
#ifndef COMPILE_NO_SF
  pumpkin1 = getGraphic("Pumpkin");
#endif
  shotx=x+width/2-20;
  shoty=y+height/2+30;
  delay=20;
}

Pumpkin::~Pumpkin() {
  for (unsigned int i=0;i<bullets.size();i++)
    delete bullets[i];
  bullets.clear();
  if (ghostR)
    delete ghostR;
  if (ghostL)
    delete ghostL;
}

void Pumpkin::attack1() {
  if (ticks%25==0) {
    float yx,yy;
    getObjectCenter(you,yx,yy);
    yy+=level->getY();
    float angle = atan2(yy-shoty,yx-shotx);
    bullets.push_back(new PBullet2(level,shotx,shoty,you,angle));
  }
}

void Pumpkin::attack2() {
  if (ticks%45==1) {
    int turn = (ticks/45)%5;
    int diff = 15;
    float angle = (270-(diff*2)+turn*diff)*3.14159/180;
    bullets.push_back(new PSpawner(level,shotx,shoty,you,angle,&bullets));
  }
}
void Pumpkin::attack3() {
  if (ticks%8==0) {
    float pi = 3.1415926535;
    float rate=1.2;
    bullets.push_back(new PBullet2(level,shotx,shoty,you,(ticks/rate)*pi/180));
    bullets.push_back(new PBullet2(level,shotx,shoty,you,(ticks/rate)*pi/180+pi/2));
    bullets.push_back(new PBullet2(level,shotx,shoty,you,ticks/rate*pi/180+pi));
    bullets.push_back(new PBullet2(level,shotx,shoty,you,ticks/rate*pi/180-pi/2));
  }
}
void Pumpkin::attack4() {
  if (ticks%45==0) {
    float x = getRand(40,640);
    bullets.push_back(new Vine(level,x,you));
  }
}
void Pumpkin::attack5() {
  if (ticks%360==1) {
    bullets.push_back(new WallVine(level,(ticks/360)%2,you));
  }
}


void Pumpkin::act() {
  if (you->getDead())
    part=-1;
  for (unsigned int i=0;i<bullets.size();i++) {
    bullets[i]->act();
    if (bullets[i]->isGone()) {
      delete bullets[i];
      bullets.erase(bullets.begin()+i);
      i--;
    }
  }
  if (!you->getDead()) {
    if (ghostL)
      ghostL->act();
    if (ghostR)
      ghostR->act();
  }
  if (part!=-1)
    ticks++;
  if (part!=-1&&delay) {
    ticks--;
    delay--;
  }
  else if (part==1) {
    attack1();
    if (ticks>4*100) {
      part=2;
      ticks=0;
      delay=15;
    }
  }
  else if (part==2) {
    attack2();
    if (ticks>45*8) {
      ticks=0;
      part=3;
      delay=75;
    }
  }
  else if (part==3) {
    attack3();
    if (ticks>360*2) {
      ticks=0;
      part=4;
      delay=30;
    }
  }
  else if (part==4) {
    attack1();
    attack2();
    if (ticks>45*8) {
      ticks=0;
      part=5;
    }
  }
  else if (part==5) {
    attack1();
    if (ticks>60) {
      delay=30;
      part=6;
    }
  }
  else if (part==6) {
    attack3();
    attack2();
    if (ticks>45*8) {
      ticks=0;
      part=7;
      delay=40;
    }
  }
  else if (part==7) {
    attack4();
    if (ticks>45*20) {
      ticks=0;
      part=8;
    }
  }
  else if (part==8) {
    attack5();
    attack4();
    if (ticks>45*15) {
      ticks=0;
      part=9;
    }
  }
  else if (part==9) {
    attack2();
    attack4();
    if (ticks>45*15) {
      ticks=0;
      part=10;
      delay=90;
      ghostL = new PGhost(level,true,you,&bullets);
      ghostR = new PGhost(level,false,you,&bullets);
      
    }
  }
  else if (part==10) {
    attack1();
    attack4();
    if (ticks>45*15) {
      ticks=0;
      part=11;
      delay=20;
    }
  }
  else if (part==11) {
    attack2();
    attack4();
    attack5();
    if (ticks>45*20) {
      //dies
      part=12;
      you->beatBoss3();
      delete ghostL;
      delete ghostR;
      ghostL=ghostR=NULL;
    }
  }
}

#ifndef COMPILE_NO_SF
void Pumpkin::render(sf::RenderWindow& window) {
  pumpkin.setPosition(getX1(),getY1());
  pumpkin.setTexture(pumpkin1);
  window.draw(pumpkin);
  if (part==12) {
    r-=2;
    if (r<-180)
      r=-180;
  }
  else if (part>=4) {
    r+=dir/2.0;
    if (part>=7)
      r+=dir/2.0;
    if (part>=9)
      r+=dir;
    if (part>=11)
      r+=dir*2;
    if (r>53)
      dir=-1;
    if (r<0)
      dir=1;
  }
  if (part==12) 
    pumpkin.setColor(sf::Color(200+r,200+r,200+r,180+r));
  else
    pumpkin.setColor(sf::Color(200+r,200,200,180));
  for (unsigned int i=0;i<bullets.size();i++)
    bullets[i]->render(window);
  
  if (ghostL)
    ghostL->render(window);
  if (ghostR)
    ghostR->render(window);
}
#endif
