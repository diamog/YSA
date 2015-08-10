#include "stdafx.h"
#include "Boss3_2.h"
#include "../Switables/RedSwitch.h"
#include "../Platforms/Platform.h"
#include "../Platforms/ThinPlat.h"
#include "../Enemies/CloudBoss.h"
#include "../Extras/utilities.h"
#include "../SpeechBubble.h"
#include "../Switables/Save.h"
#include <iostream>
#include <cstdlib>

Boss3_2::Boss3_2(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  isMove=false;
  if (!you->boss2()) {
    isboss=true;
  }
  top=NULL;
  movePlat=false;
  boss=NULL;
  me = CLOUD2;
  if (!you->boss2()) {
    boss = new CloudBoss2(this,you);
    actors.push_back(boss);
  }

  setup();
  if (ent== EAST) {
    if (!you->boss2Half()) {
      you->beatBoss2Half();
      isMove=true;
      you->controlPause();
    }
    you->setPosition(698,entery,true);
  }
  else
    throw THROW_ENTRANCE_ERROR;
}

void Boss3_2::makePlatforms() {
  actors.push_back(new Platform(this,0,580,700,30,you));
  actors.push_back(new Platform(this,0,-30,30,610,you));
  right = new Platform(this,670,0,30,450,you);
  actors.push_back(right);
  actors.push_back(new Platform(this,570,500,100,25,you));
  actors.push_back(new Platform(this,470,380,100,25,you));
  actors.push_back(new Platform(this,130,300,100,25,you));
  if (you->boss2()||!you->boss2Half()) {
    top = new Platform(this,300,100,150,25,you);
    actors.push_back(top);
  }
  if (you->boss2Half())
    actors.push_back(new Platform(this,30,0,640,25,you));
  
}
void Boss3_2::makeEnemies() {
  if (!you->boss2()) {
    eye = new SmallEye(this,680-35,320,you,3);
    actors.push_back(eye);
  }
}
void Boss3_2::makeCollectables() {
  buildHint(340,535,0,"Use the left and right arrow keys to explode.;");
  buildHint(585,465,1,"Use the up arrow key to die.;");
  buildHint(540,345,2,"In mid air use the up arrow key to burn.;");
  buildHint(250,150,3,"The sooner you double jump the sooner you die.;");
  buildExtra(635,10);
}

void Boss3_2::makeSwitches() {
  //Make the save point 
  //actors.push_back(new Save(this,130,230,40,you,NOT_SAVE));
}

void Boss3_2::makeDetectors() {
  if (!you->boss2()) {
    b1 = new BigEye(this,650,300,NOTHING,eye);
    detectors.push_back(b1);
    b2 = new BigEye(this,-10,300,EYE_1,eye);
    detectors.push_back(b2);
  }
}

Level* makeBoss3_2(You* yo, float x, float y, ENT_CODE ent) {
  return new Boss3_2(yo,x,y,ent);
}

void Boss3_2::act() {
  if (!you->boss2()&&you->getX2()>700)
    you->setPosition(700-you->getWidth(),you->getY1(),true);
    
  if (you->getX2()<670&&right->getHeight()<600&&!you->boss2()) {
    right->setHeight(right->getHeight()+5);
    if (isRectangularHit(you,right) && getApproachDirection(you,right)==-1)
	you->die();
  }
  if (isMove) {
    you->shiftX(-7);
    if (you->getX1()<=37)
      isMove=false;
  }
  if (boss) {
    if (boss->getY1()<=125&&top&&top->getY1()>0) {
      movePlat=true;
    }
    if (movePlat&&top&&top->getY1()>0) {
      top->setPosition(top->getX1(),boss->getY1()-25);
    }
    else if (movePlat&&top&&top->getX1()>30) {
      top->setPosition(top->getX1(),0);
      top->shiftX(-3);
      top->setWidth(top->getWidth()+6);
    }
    if (boss->getAlpha()<=0) {
      remove(boss);
      boss=NULL;
    }
  }
  Level::act();
  
}

bool Boss3_2::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getX1()>700) {
    next_level=CLOUD;
    ent_type=WEST;
    return true;
  }
  return Level::isChangeRoom(next_level,ent_type);
}


void Boss3_2::sendEvent(EVE_CODE eve, Actor* sender) {
  if (eve==RED_1) {
    if (b1->isOn()) eye->start();
  }
  else if (eve==EYE_1) {
    if (!you->getDead()&&boss) {
      isboss=false;
      you->beatBoss2();
      you->messagePause();
      actors.push_back(new SpeechBubble(this,"Urk... As the haze fades so too do I...;",
					sf::Color(140,140,140),
					you->getY1(),MISCE_1));
   
    }
  }
  else if (eve==MISCE_1) {
    you->messagePause();
    actors.push_back(boss->kill());
  }
  else
    Level::sendEvent(eve,sender);
}
