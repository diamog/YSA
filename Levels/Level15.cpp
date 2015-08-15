#include "stdafx.h"
#include "Level15.h"
#include "../Platforms/Platform.h"
#include "../Platforms/ThinPlat.h"
#include "../Switables/Portal.h"
#include "../Switables/Save.h"
#include "../Enemies/DeathArea.h"
#include "../SpeechBubble.h"
#include <iostream>

Level15::Level15(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  me = ELEVATOR;
  isPortal=false;
  setup();
  if (ent== PORTAL_1) {
    you->setPosition(340,height-150,true);
  }
  else if (ent== LOAD_1) {
    //Load into savepoint 1
    you->setPosition(340,height-150);
  } 
  else if (ent==LOAD_2) {
    you->setPosition(500,410);
  }
  else if(ent==LOAD_3) {
    you->setPosition(698,entery,true);
  }
  else
    throw THROW_ENTRANCE_ERROR;
}


void Level15::makePlatforms() {
  actors.push_back(new Platform(this,0,0,20,height,you));
  actors.push_back(new Platform(this,680,0,20,height,you));
  elevator = new Platform(this,20,height-50,660,20,you);
  actors.push_back(elevator);
  
}
void Level15::makeEnemies() {
}
void Level15::makeCollectables() {
  //Make the hints
  //buildExtra(630,310);
}

void Level15::makeSwitches() {
  //Make the save point
  buildSave(330,height-160,TOWER_START,HARD);
  //temporaru portal to leave tower
  actors.push_back(new Portal(this,20,30,660,20,you,PORTALE_1));
}

void Level15::act() {
  elevator->shiftY(-1);
  if (you->getPlat()==elevator) {
    you->land(elevator);
  }
  Level::act();
}

Level* makeLevel15(You* yo, float x, float y, ENT_CODE ent) {
  return new Level15(yo,x,y,ent);
}

bool Level15::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (isPortal) {
    next_level=SPLIT;
    ent_type=PORTAL_2;
    return true;
  }
  if (you->getY2()<0) {
    next_level=TOWEREND;
    ent_type=SOUTH;
    return true;
  }
  return Level::isChangeRoom(next_level,ent_type);
}

void Level15::sendEvent(EVE_CODE event,Actor* sender) {
  if (event==PORTALE_1) {
    isPortal=true;
  }
  else 
    Level::sendEvent(event,sender);
  
}
