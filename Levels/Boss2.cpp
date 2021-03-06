#include "stdafx.h"
#include "Boss2.h"
#include "../Platforms/KickPlat.h"
#include "../Extras/utilities.h"
#include "../SpeechBubble.h"
#include <iostream>
#include <cstdlib>

Boss2::Boss2(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  isboss=true;
  me = PUMPKIN;
  part=0;
  height=1200;
  canMove=false;
  setup();
  headL=headR=NULL;
  if (ent== NORTH) {
    you->setPosition((enterx-3420+670),1,true);
  }
  else
    throw THROW_ENTRANCE_ERROR;
  if (you->boss3()) {
    part=5;
    canMove=true;
    sendEvent(MISCE_3,NULL);
    you->messagePause();
  }
  else if (you->boss3Half()) {
    sendEvent(MISCE_3,NULL);
    sendEvent(MISCE_4,NULL);
    canMove=true;
    part=2;
  }
  
}
template <class Plat,class KPlat>
void Boss2::makeP() {
  plat1 = new Plat(this,30,530,640,10,you);
  actors.push_back(plat1); //floor
  actors.push_back(new KPlat(this,0,0,30,1200,you,false,true)); //left wall
  actors.push_back(new KPlat(this,670,0,30,1200,you,true,false)); //right wall
  actors.push_back(new Plat(this,0,1170,700,30,you));
  actors.push_back(new Plat(this,250,600+200,200,30,you));

}

void Boss2::makePlatforms() {
  makeP<Platform,KickPlat>();
}
void Boss2::makeEnemies() {
  if (!you->boss3()) {
    pumpkin = new Pumpkin(this,you);
    actors.push_back(pumpkin);
  }
}
void Boss2::makeCollectables() {
  
  buildExtra(350-25/2,835);
}


Level* makeBoss2(You* yo, float x, float y, ENT_CODE ent) {
  return new Boss2(yo,x,y,ent);
}

void Boss2::act() {
  Level::act();
  if (you->getY1()<0) {
    you->setPosition(you->getX1(),0);
    you->setFall();
  }
  if (you->getX1()<=340&&part==0) {

    if (!you->hasEntered(3)) {
      you->controlPause();    
      actors.push_back(new SpeechBubble(this,"Hmmm no way out.;",
					sf::Color(255,255,0),you->getY1(),MISCE_1));
    }
    else
      sendEvent(MISCE_1,NULL);
    part=1;
  }
  else if (part==2&&you->getPlat()) {
    sendEvent(MISCE_5,NULL);
    part=3;
    canMove=false;
  }
  else if (part==1&&headL!=NULL&&headR!=NULL&&headL->getNumStems()+headR->getNumStems()<=10) {
    headL->turnOff();
    headR->turnOff();
    if (headL->getY1()>=600&&headR->getY1()>=600) {
      you->setPosition(you->getX1(),you->getY1());
      sendEvent(MISCE_3,NULL);
      part=2;
      canMove=true;
      you->beatBoss3Half();
    }
  }
  else if (part==3) {
    y+=5;
    you->shiftY(-5);
    if (y>=height-600) {
      part=4;
      y=height-600;
      you->setPosition(you->getX1(),you->getPlat()->getY1()-you->getHeight());
    }
  }
}

bool Boss2::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getY2()<0) {
    next_level=COLLECTOR;
    ent_type=SOUTH;
  }
  return Level::isChangeRoom(next_level,ent_type);
}


void Boss2::sendEvent(EVE_CODE eve, Actor* sender) {
  if (eve==MISCE_1) {
    remove(sender);
    if (!you->hasEntered(3)) {
      actors.push_back(new SpeechBubble(this,"Weedle. Tweedle. Caught in our trap!; This yellow square is about to be zap zapped.;",sf::Color(255,165,0),you->getY1(),MISCE_2));
    }
    headL = new PumpkinHead(this,150,you,14);
    actors.push_back(headL);
    headR = new PumpkinHead(this,480,you,14);
    actors.push_back(headR);
    headL->connect(headR);
    headR->connect(headL);
  }
  else if (eve==MISCE_2) {
    you->enter(3);
    remove(sender);
    you->controlPause();
  }
  else if (eve==MISCE_3) {
    you->messagePause();
    remove(headL);
    remove(headR);
    remove(plat1);
#ifndef COMPILE_NO_SF
    if (!you->boss3Half()) 
      actors.push_back(new SpeechBubble(this,"You there destroying my stems.; I want to have a word with you.;",sf::Color(255,165,0),you->getY1(),MISCE_4));

#endif
    
  }
  else if (eve==MISCE_4) {
    remove(sender);
    you->messagePause();
    you->controlPause();
    
  }
  else if (eve==MISCE_5) {
    you->land(you->getPlat());
    if (!you->hasEntered(4)) {
      actors.push_back(new SpeechBubble(this,"Ah you are the pesky square that destroyed the Color Eater huh?; Hah the color may be back but you will not restore the design as easily; Now hold still so I can blast you!;",sf::Color(255,165,0),you->getY1(),MISCE_6));
      you->enter(4);
    }
    else
      sendEvent(MISCE_6,NULL);
    
  }
  else if (eve==MISCE_6) {
    remove(sender);
    you->controlPause();
    you->setFall();
    pumpkin->turnOn();
  }
  else
    Level::sendEvent(eve,sender);

}
