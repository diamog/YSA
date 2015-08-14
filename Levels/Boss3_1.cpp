#include "stdafx.h"
#include "Boss3_1.h"
#include "../Switables/RedSwitch.h"
#include "../Platforms/Platform.h"
#include "../Platforms/ThinPlat.h"
#include "../Enemies/CloudBoss.h"
#include "../Extras/utilities.h"
#include "../SpeechBubble.h"
#include <iostream>
#include <cstdlib>

Boss3_1::Boss3_1(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  if (!you->boss2Half())
    isboss=true;
  me = CLOUD;
  eye=NULL;
  b1=NULL;
  b2=NULL;
  boss=NULL;
  setup();
  dir=-1;
  if (ent== WEST) {
    you->setPosition(-18,entery,true);
  }
  else if (ent==SOUTH) {
    you->setPosition(enterx,598,true);
    if (!you->boss2Half()) {
      you->controlPause();
      actors.push_back(new SpeechBubble(this,"You... You are not welcome here. You destroyed my dear friend.; You removed the gray and brought this.; I will show you the gray!;",
					sf::Color(140,140,140),
					you->getY1(),MISCE_1));
    }
  }
  else
    throw THROW_ENTRANCE_ERROR;
  if (you->boss2Half()) {
    sendEvent(EYE_1,NULL);
  }
}

void Boss3_1::makePlatforms() {
 actors.push_back(new Platform(this,0,580,530,50,you));
 actors.push_back(new Platform(this,670,0,30,630,you));
 left = new Platform(this,0,0,30,580,you);
 actors.push_back(left);
 actors.push_back(new Platform(this,30,0,640,30,you));
 if (!you->boss2Half()) 
   actors.push_back(new Platform(this,500,580,170,30,you));
 
}
void Boss3_1::makeEnemies() {
  if (!you->boss2Half()) {
    eye = new SmallEye(this,680-35,540,you,3);
    actors.push_back(eye);
    boss = new CloudBoss1(this,you,eye);
    actors.push_back(boss);
  }
}
void Boss3_1::makeCollectables() {
  //buildExtra(635,35);
}

void Boss3_1::makeSwitches() {
  if (!you->boss2Half()) 
    actors.push_back(new RedSwitch(this,45,540,30,you,RED_1));
}

void Boss3_1::makeDetectors() {
  if (!you->boss2Half()) {
    b1 = new BigEye(this,680-35,520,NOTHING,eye);
    detectors.push_back(b1);
    b2 = new BigEye(this,-10,300,EYE_1,eye);
    detectors.push_back(b2);
  }
}

Level* makeBoss3_1(You* yo, float x, float y, ENT_CODE ent) {
  return new Boss3_1(yo,x,y,ent);
}

void Boss3_1::act() {
  Level::act();
  if (boss) {
    if (boss->isPart2()) {
      b1->shiftY(dir*2);
      if (you->getDifficulty()>=HARD)
	b1->shiftY(dir*2);
      if (b1->isOn()) {
	eye->shiftY(dir*2);
	if (you->getDifficulty()>=HARD)
	  eye->shiftY(dir*2);
      }
      else {
	float bx,by;
	getObjectCenter(b1,bx,by);
	eye->setReset(bx,by);
      }
      if (b1->getY1()<30)
	dir=1;
      else if (b1->getY2()>570)
	dir=-1;
       
    }
    if (b2->isOn()&&!you->isPauseM()) {
      you->shiftX(-7);
    }
  }
}

bool Boss3_1::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getX2()<0) {
    next_level=CLOUD2;
    ent_type=EAST;
    return true;
  }
  if (you->getY1()>600) {
    next_level=PREBOSS2;
    ent_type=NORTH;
    return true;
  }
  return Level::isChangeRoom(next_level,ent_type);
}


void Boss3_1::sendEvent(EVE_CODE eve, Actor* sender) {
  if (eve==RED_1) {
    if (b1->isOn()) eye->start(7);
  }
  else if (eve==EYE_1) {
    isboss=false;
    left->setHeight(450);
    if (!you->boss2Half()) {
      you->messagePause();
      actors.push_back(new SpeechBubble(this,"I will not die to the likes of you.; My storms will destroy you!;",
					sf::Color(140,140,140),
					you->getY1(),MISCE_2));

    }
  }
  else if (eve==MISCE_1) {
    remove(sender);
    you->controlPause();
    boss->start();
  }
  else if (eve==MISCE_2) {
    remove(sender);
    you->messagePause();
    you->controlPause();
  }

  else
    Level::sendEvent(eve,sender);
}
