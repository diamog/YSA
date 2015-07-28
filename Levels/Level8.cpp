#include "stdafx.h"
#include "Level8.h"
#include "../Switables/Portal.h"
#include "../Platforms/Platform.h"
#include "../Platforms/KickPlat.h"
#include "../Switables/Save.h"
#include "../Enemies/DeathArea.h"
#include <iostream>

Level8::Level8(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  me = CLIMB;
  height=1470;
  if (ent==EAST) {
    you->setPosition(698,(entery-800)+30,true);
  } 
  else if(ent==SOUTH) {
    you->setPosition(enterx,height-2,true);
  }
  else if (ent==LOAD_1) {
    you->setPosition(510,65);
  }
  else
    throw THROW_ENTRANCE_ERROR;
  setup();
}


void Level8::makePlatforms() {
  //Top of wall kicking
  actors.push_back(new Platform(this,220,0,700-220,30,you));
  actors.push_back(new Platform(this,480,130,700-480,30,you));
  actors.push_back(new KickPlat(this,220,30,30,1470,you,false,true));
  actors.push_back(new KickPlat(this,450,130,30,1390,you,true,false));

}
void Level8::makeEnemies() {
  actors.push_back(new DeathArea(this,330,290,120,30,you));
  actors.push_back(new DeathArea(this,250,390,70,30,you));
  actors.push_back(new DeathArea(this,410,440,40,30,you));
  actors.push_back(new DeathArea(this,320,510,60,30,you));
  actors.push_back(new DeathArea(this,250,590,30,30,you));
  actors.push_back(new DeathArea(this,300,720,150,40,you));
  actors.push_back(new DeathArea(this,250,850,100,40,you));
  actors.push_back(new DeathArea(this,320,890,30,150,you));
  actors.push_back(new DeathArea(this,250,1070,50,30,you));
  actors.push_back(new DeathArea(this,250,1070,50,30,you));
  actors.push_back(new DeathArea(this,390,1160,60,30,you));
  actors.push_back(new DeathArea(this,390,1240,60,30,you));
  actors.push_back(new DeathArea(this,250,1290,70,30,you));
  actors.push_back(new DeathArea(this,325,1360,50,30,you));

}
void Level8::makeCollectables() {
  //Make the hints
  buildExtra(250+35-25.0/2,950);
}

void Level8::makeSwitches() {
  //Make the save point
  actors.push_back(new Save(this,500,55,40,you,PRE_KICK_HALL));
  actors.push_back(new Portal(this,255,895,60,25,you,PORTALE_1));
}
void Level8::makeDetectors() {
  //detectors.push_back(new Detector(this,0,570-30,30,30,&actors2));
}

Level* makeLevel8(You* yo, float x, float y, ENT_CODE ent) {
  return new Level8(yo,x,y,ent);
}


void Level8::sendEvent(EVE_CODE eve, Actor* sender) {
  if (eve==PORTALE_1) {
    y=height-600;
    you->setPosition(425,600-255);
  }
  else
    Level::sendEvent(eve,sender);
}

bool Level8::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getX1()>700) {
    next_level=COLLECTOR;
    ent_type=WEST;
    return true;
  }
  if (you->getY1()>600) {
    next_level=KICK;
    ent_type=NORTH;
    return true;
  }
  return Level::isChangeRoom(next_level,ent_type);
}
