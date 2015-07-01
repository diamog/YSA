#include "stdafx.h"
#include "Level3.h"
#include "../Platforms/Platform.h"
#include "../Platforms/ThinPlat.h"
#include "../Switables/Hint.h"
#include "../Switables/Save.h"
#include "../Enemies/DeathArea.h"
#include <iostream>
#include "../Platforms/VerticalPlat.h"

Level3::Level3(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  me = MOVING;
  setup();
  if (ent== WEST) {
    //Move from room 2
    you->setPosition(-18,entery);
    
  }
  else if (ent==EAST) {
    //Move from Boss 1

  }
  else if (ent== LOAD_1) {
    //Load into savepoint 2
    you->setPosition(600,60);
  }  
  else
    throw THROW_ENTRANCE_ERROR;
}


void Level3::makePlatforms() {
  actors.push_back(new Platform(this,0,0,700,30,you)); //top wall
  actors.push_back(new Platform(this,0,150,30,450,you)); //left wall
  actors.push_back(new Platform(this,670,150,30,450,you)); //right wall
  actors2.push_back(new VertPlat(this,80,300,40,you,true));
  actors2.push_back(new VertPlat(this,250,500,40,you,true));
  actors2.push_back(new VertPlat(this,590,200,40,you,false));
  
  
}
void Level3::makeEnemies() {
  actors.push_back(new DeathArea(this,30,570,640,30,you));
  actors.push_back(new DeathArea(this,170,30,30,350,you));
  actors.push_back(new DeathArea(this,340,30,30,50,you));
  actors.push_back(new DeathArea(this,340,220,30,250,you));
  actors.push_back(new DeathArea(this,510,30,30,380,you));
}
void Level3::makeCollectables() {
  //Make the hints
  buildHint(670,120,7,"Warning! Danger ahead proceed with caution.;");
  buildHint(425,200,8,"Hold the down key is mid air to fall faster.;");
  buildExtra(345,510);
}

void Level3::makeSwitches() {
  //Make the save point 
  actors.push_back(new Save(this,590,50,40,you,ROOM_3));
}

void Level3::makeDetectors() {
  detectors.push_back(new Detector(this,80,60,40,40,&actors2));
  detectors.push_back(new Detector(this,80,590,40,40,&actors2));
  detectors.push_back(new Detector(this,250,60,40,40,&actors2));
  detectors.push_back(new Detector(this,250,590,40,40,&actors2));
  detectors.push_back(new Detector(this,590,60,40,40,&actors2));
  detectors.push_back(new Detector(this,590,590,40,40,&actors2));
}

Level* makeLevel3(You* yo, float x, float y, ENT_CODE ent) {
  return new Level3(yo,x,y,ent);
}

bool Level3::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getX2()<0) {
    next_level=DIE;
    ent_type=EAST;
    return true;
  }
  if (you->getX1()>700) {
    next_level=COLOR;
    ent_type=WEST;
    return true;
  }
  return false;
}
