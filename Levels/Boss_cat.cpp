#include "stdafx.h"
#include "Boss_cat.h"
#include "../Platforms/Platform.h"
#include "../Platforms/ThinPlat.h"
#include "../Switables/Portal.h"
#include "../Switables/Save.h"
#include "../Enemies/DeathArea.h"
#include "../SpeechBubble.h"
#include <iostream>

BossCat::BossCat(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  me = CAT_1;
  isPortal=false;
  boss=NULL;
  isboss=true;
  setup();
  if (ent== WEST) {
    you->setPosition(-18,entery,true);
  }
  else
    throw THROW_ENTRANCE_ERROR;
}


void BossCat::makePlatforms() {
  actors.push_back(new Platform(this,0,height-30,700,30,you));  
}

void BossCat::makeEnemies() {
  if (!you->boss4()) {
    boss = new CatBoss(this,you);
    actors.push_back(boss);
  }
}
void BossCat::makeCollectables() {
  //Make the hints
  //buildExtra(630,310);
}


void BossCat::act() {
  Level::act();
  if (boss) {
    if (you->getX1()<0)
      you->setPosition(0,you->getY1());
    if (you->getX2()>700)
      you->setPosition(700-you->getWidth(),you->getY1());
    if (you->getY1()<0) {
      you->setPosition(you->getX1(),0);
      you->setFall();
    }
  }
}

Level* makeBossCat(You* yo, float x, float y, ENT_CODE ent) {
  return new BossCat(yo,x,y,ent);
}

bool BossCat::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (isPortal) {
    next_level=SPLIT;
    ent_type=PORTAL_2;
    return true;
  }
  if (you->getX2()<0) {
    next_level=TOWEREND;
    ent_type=EAST;
    return true;
  }
  return Level::isChangeRoom(next_level,ent_type);
}

void BossCat::sendEvent(EVE_CODE event,Actor* sender) {
  if (event==PORTALE_1) {
    isPortal=true;
  }
  else 
    Level::sendEvent(event,sender);
  
}
