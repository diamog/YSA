#include "stdafx.h"
#include "Boss3_1.h"
#include "../Switables/RedSwitch.h"
#include "../Platforms/Platform.h"
#include "../Platforms/ThinPlat.h"
//#include "../Enemies/Cloud.h"
#include "../Extras/utilities.h"
#include "../SpeechBubble.h"
#include <iostream>
#include <cstdlib>

Boss3_1::Boss3_1(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  isboss=true;
  me = CLOUD;
  setup();
  if (ent== WEST) {
    you->setPosition(-18,entery,true);
  }
  else if (ent==SOUTH) {
    you->setPosition(enterx,598,true);
  }
  else
    throw THROW_ENTRANCE_ERROR;
}

void Boss3_1::makePlatforms() {
 actors.push_back(new Platform(this,0,580,500,50,you));
 actors.push_back(new Platform(this,670,0,30,630,you));
 actors.push_back(new Platform(this,0,0,30,580,you));
 actors.push_back(new Platform(this,30,0,640,30,you));
 actors.push_back(new Platform(this,500,580,170,30,you));
 
 actors.push_back(new Platform(this,500,600,180,30,you));
}
void Boss3_1::makeEnemies() {
  eye = new SmallEye(this,680-35,530,you,3);
  actors.push_back(eye);
  /*if (!you->boss2()) {
    boss = new ColorBoss(this,700,-50,50,50,you);
    actors.push_back(boss);
    }*/
}
void Boss3_1::makeCollectables() {
  //buildExtra(635,35);
}

void Boss3_1::makeSwitches() {
  actors.push_back(new RedSwitch(this,45,540,30,you,RED_1));
}

void Boss3_1::makeDetectors() {
  b1 = new BigEye(this,680-35,510,NOTHING,eye);
  detectors.push_back(b1);
  b2 = new BigEye(this,-10,300,EYE_1,eye);
  detectors.push_back(b2);
}

Level* makeBoss3_1(You* yo, float x, float y, ENT_CODE ent) {
  return new Boss3_1(yo,x,y,ent);
}

void Boss3_1::act() {
  Level::act();
}

bool Boss3_1::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
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


void Boss3_1::sendEvent(EVE_CODE eve, Actor* sender) {
  if (eve==RED_1) {
    if (b1->isOn()) eye->start();
  }
  else
    Level::sendEvent(eve,sender);
}
