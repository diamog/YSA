#include "stdafx.h"
#include "PumpkinHead.h"
#include "../Extras/utilities.h"
PumpkinHead::PumpkinHead() : Actor(), Enemy() {
  hp = 0;
}

PumpkinHead::PumpkinHead(Level* l, float x_, You* yo, int health) : Actor(l,x_,600,70,50), Enemy(l,x_,600,70,50,yo,health) {
  numstems=health;
  phase=0;
#ifndef COMPILE_NO_SF
  texture.loadFromFile("Graphics/pumpkin1.png");
  head.setOrigin(width/2,0);
  // shape.setFillColor(sf::Color(255,165,0));
  // eye.setFillColor(sf::Color(0,0,0));
  // shape.setRadius(height/2);
  // shape.setScale(width/height,1);
  // eye.setRadius(height/6);
#endif
  stem_height=width/2;
  ticks=0;
  eyex=0;
}

PumpkinHead::~PumpkinHead() {
  for (unsigned int i=0;i<bullets.size();i++)
    delete bullets[i];
  bullets.clear();
  for (unsigned int i=0;i<stems.size();i++)
    delete stems[i];
  stems.clear();
}
void PumpkinHead::hit() {
  tempnumstems--;
}

void PumpkinHead::act() {
  float yorig=y;
  if (phase==0) {
    tempnumstems=numstems;
    for (int i=0;i<numstems;i++) {
      if (eyex<getX1()+width/2)
	stems.push_back(new Stem(level,getX1()+width/2,getY2()+stem_height*i
				 ,getX1()+width/2,
				 stem_height,stem_height,you,-1));
      else
	stems.push_back(new Stem(level,getX1()+5,getY2()+stem_height*i
				 ,getX1()+width/2,
				 stem_height,stem_height,you,1));
    }
    phase=1;
  }
  else if (phase==1) {
    if (!you->isPauseC())
      y-=4;
    else
      y-=3;
    if (getY1()<600-stem_height*numstems) {
      texture.loadFromFile("Graphics/pumpkin2.png");
      phase=2;
    }
  }
  else if (phase==2) {
    if (!you->isPauseC())
      ticks++;
    if (ticks>120) {
      ticks=0;
      phase=3;
      float yx,yy;
      getObjectCenter(you,yx,yy);
      float eyey=getY1()+height/2-height/6;
      float angle = atan2(yy-eyey,yx-eyex);
      bullets.push_back(new PBullet(level,eyex,getY1()+height/2-height/6,
				    you,angle,other_stems));
    }
  }
  else if (phase==3) {
    ticks++;
    if (ticks>150) {
      ticks=0;
      phase=4;
      texture.loadFromFile("Graphics/pumpkin1.png");
      
    }
  }
  else if (phase==4) {
    y+=5;
    if (getY1()>600) {
      phase=5;
      for (unsigned int i=0;i<stems.size();i++) {
	if (stems[i]->getDead())
	  tempnumstems--;
	delete stems[i];
      }
      stems.clear();
      numstems=tempnumstems;
      
      x = rand()%530+50;
      y=580;
      if (you->getDead()) {
	phase=-1;
      }
    }
  }
  else if (phase==5) {
    ticks++;
    if (ticks>60) {
      ticks=0;
      phase=0;
    }
  }
  Enemy::act();
  for (unsigned int i=0;i<bullets.size();i++) {
    bullets[i]->act();
    if (bullets[i]->isGone()) {
      delete bullets[i];
      bullets.erase(bullets.begin()+i);
      i--;
    }
  }
  for (unsigned int i=0;i<stems.size();i++) {
    stems[i]->shiftY(y-yorig);
    stems[i]->act();
    
  }
  
}

#ifndef COMPILE_NO_SF
void PumpkinHead::render(sf::RenderWindow& window) {
  float cx,cy;
  float yx,yy;
  getObjectCenter(this,cx,cy);
  getObjectCenter(you,yx,yy);
  int dir=1;
  if (yx>=cx) {
    eyex=getX2()-22;
    head.setScale(-1,1);
  }
  else {
    dir=-1;
    eyex = getX1()+22;
    head.setScale(1,1);
  }
  int dir_copy=dir;
  if (phase==2) {
    sf::Vertex line[] =
    {
      sf::Vertex(sf::Vector2f(eyex,getY1()+height/2-height/6),sf::Color(140,0,0,255*.75 )),
      sf::Vertex(sf::Vector2f(yx,yy),sf::Color(140,0,0,255*.75))
    };
    window.draw(line,2,sf::Lines);

  }
  for (unsigned int i=0;i<bullets.size();i++) {
    bullets[i]->render(window);
  }
  for (unsigned int i=0;i<stems.size();i++) {
    stems[i]->setPumpDir(dir);
    stems[i]->setDir(dir_copy);
    dir_copy*=-1;
    stems[i]->render(window);
  }
  head.setTexture(texture);
  head.setPosition(getX1()+width/2,getY1());
  window.draw(head);
  
}
#endif
