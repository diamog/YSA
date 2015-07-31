#include "stdafx.h"
#include "Boss1.h"
#include "../Switables/Crystal.h"
#include "../Platforms/ColorPlat.h"
#include "../Enemies/ColorBoss.h"
#include "../Bullets/ColorBullet.h"
#include "../Extras/utilities.h"
#include "../SpeechBubble.h"
#include "../Graphics/ColorRemove.h"
#include <iostream>
#include <cstdlib>

Boss1::Boss1(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  boss=NULL;
  isboss=true;
  me = COLOR;
  setup();
  if (boss!=NULL) {
    
    fairy = new Fairy(this,30,515);
    fairy->kill();
    actors.push_back(fairy);
  }
  if (ent== WEST) {
    //Move from room 2
    you->setPosition(-18,entery,true);
  }
  else if (ent==SOUTH) {
    //Move from split room
    you->setPosition(enterx,598,true);
  }
  else
    throw THROW_ENTRANCE_ERROR;
}
template <class Plat,class TPlat>
void Boss1::makeP() {
  
  actors.push_back(new Plat(this,0,0,700,30,you)); //top wall
  actors.push_back(new Plat(this,0,150,30,500,you)); //left wall
  actors.push_back(new Plat(this,670,30,30,650,you)); //right wall
  actors.push_back(new TPlat(this,30,570,740,you));
  actors.push_back(new TPlat(this,130,290,40,you));
  actors.push_back(new TPlat(this,220,420,40,you));
  actors.push_back(new TPlat(this,380,95,40,you));
  actors.push_back(new TPlat(this,380,370,40,you));
  actors.push_back(new TPlat(this,550,480,40,you));
  actors.push_back(new TPlat(this,570,250,40,you));
}

void Boss1::makePlatforms() {
  if (!you->boss1())
    makeP<ColorPlatform,ColorPlat>();
  else
    makeP<Platform,ThinPlat>();
}
void Boss1::makeEnemies() {
  if (!you->boss1()) {
    boss = new ColorBoss(this,700,-50,50,50,you);
    actors.push_back(boss);
  }
}
void Boss1::makeCollectables() {
  int dx = 740/4;
  if (!you->boss1()) {
    actors.push_back(new Crystal(this,30.0f+dx,500,20,60,you,"red"));
    actors.push_back(new Crystal(this,30.0f+dx*2,500,20,60,you,"green"));
    actors.push_back(new Crystal(this,30.0f+dx*3,500,20,60,you,"blue"));
  }
  buildExtra(635,35);
}


Level* makeBoss1(You* yo, float x, float y, ENT_CODE ent) {
  return new Boss1(yo,x,y,ent);
}

void Boss1::act() {
  Level::act();
  if (boss!=NULL) {
    bool isAlive = boss->isAlive();
    if (isAlive) {
      if (you->getX1()<0)
        you->setPosition(0,you->getY1());
      else if (you->getY2()>600)
        you->setPosition(you->getX1(),600-(you->getY2()-you->getY1()));
      for (unsigned int i=0;i<actors.size();i++)
        actors[i]->setColor(boss->getR(),boss->getG(),boss->getB());
    }
    else  {
      you->beatBoss1();
      fairy->turnOn(2);
      remove(boss);
      you->setFall();
      boss=NULL;
      for (unsigned int i=0; i<actors.size();i++) {
        if (dynamic_cast<ThinPlat*>(actors[i])) {
          delete actors[i];
          actors.erase(actors.begin()+i);
          i--;
        }
      }
    }
  }
}

bool Boss1::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getX2()<0) {
    next_level=MOVING;
    ent_type=EAST;
    return true;
  }
  if (you->getY1()>600) {
    next_level=SPLIT;
    ent_type=NORTH;
    if (!you->hasSplit())
      ent_type=MISC_1;
    return true;
  }
  return Level::isChangeRoom(next_level,ent_type);
}


void Boss1::sendEvent(EVE_CODE eve, Actor* sender) {
  if (eve==MISCE_1) {
    //create color bullet for you
   
    float cx,cy;
    getObjectCenter(sender,cx,cy);
    you->addBullet(new ColorBullet(this,cx,cy,5,5,sender->getMessage(),
				   boss,sender->getVal()));
    float xnew = rand()%600+50;
    float ynew = rand()%400+100;
    sender->setPosition(xnew,ynew);
    if (sender->getVal()<=0)
      remove(sender);
  }
   
  else if (eve==MISCE_2) {
#ifndef COMPILE_NO_SF
    you->messagePause();
    actors.push_back(new SpeechBubble(this,"Erk! What is THAT?!;",
				      sf::Color(255,255,0),you->getY1(),MISCE_3));
#endif
  }
  else if (eve==MISCE_3) {
    
    remove(sender);
#ifndef COMPILE_NO_SF
    actors.push_back(new SpeechBubble(this,"COLOR!!! MUST EAT COLOR!!!;",
				      sf::Color(255,255,255),you->getY1(),END_HINT));
#endif
  }
  else if (eve==MISCE_4) {
    float bx,by;
    getObjectCenter(boss,bx,by);
    actors.push_back(new ColorRemove(this,sf::Color(255,0,0),bx,by));
  }
  else if (eve==MISCE_5) {
    float bx,by;
    getObjectCenter(boss,bx,by);
    actors.push_back(new ColorRemove(this,sf::Color(0,255,0),bx,by));
  }
  else if (eve==MISCE_6) {
    float bx,by;
    getObjectCenter(boss,bx,by);
    actors.push_back(new ColorRemove(this,sf::Color(0,0,255),bx,by));
  }
  else
    Level::sendEvent(eve,sender);

}
