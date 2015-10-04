#include "stdafx.h"
#include "Level16.h"
#include "../Platforms/Platform.h"
#include "../Platforms/ThinPlat.h"
#include "../Switables/Portal.h"
#include "../Switables/Save.h"
#include "../Enemies/DeathArea.h"
#include "../SpeechBubble.h"
#include <iostream>

Level16::Level16(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  me = ELEVATOR;
  setup();
  if (ent==SOUTH) {
    you->setPosition(enterx,598,true);
  }
  else if (ent== LOAD_1) {
    you->setPosition(340,height-150);
  } 
  else if (ent==WEST) {
    you->setPosition(-18,entery,true);
  }
  else if (ent==EAST) {
    you->setPosition(698,entery,true);
  }
  else
    throw THROW_ENTRANCE_ERROR;
}


void Level16::makePlatforms() {
  actors.push_back(new ThinPlat(this,0,560,700,you));
}

void Level16::makeCollectables() {  
  buildExtra(200,50);
}

void Level16::makeSwitches() {
  //Make the save point
  buildSave(330,450,TOWER_TOP,HARD);
}


Level* makeLevel16(You* yo, float x, float y, ENT_CODE ent) {
  return new Level16(yo,x,y,ent);
}

bool Level16::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getX2()<0) {
    next_level=FIRE_1;
    ent_type=EAST;
    return true;
  }
  if (you->getX1()>700) {
    next_level=CAT_1;
    ent_type=WEST;
    return true;
  }
  return Level::isChangeRoom(next_level,ent_type);
}

