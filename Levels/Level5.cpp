#include "stdafx.h"
#include "Level5.h"
#include "../Platforms/Platform.h"
#include "../Platforms/Slope.h"
#include "../Switables/Hint.h"
#include "../Switables/Save.h"
#include "../Enemies/DeathArea.h"
#include "Follower.h"
#include "RedSwitch.h"
#include <iostream>

Level5::Level5(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  setup();
  me = FOLLOW;
  if (ent== WEST) {
    you->setPosition(-18,entery);		
  } 
  else if(ent==EAST) {
    you->setPosition(698,entery);
  }
  else
    throw THROW_ENTRANCE_ERROR;
}


void Level5::makePlatforms() {
  actors.push_back(new Slope(this,120,530,550,30,you,17.65));
  actors.push_back(new Slope(this,30,355,400,30,you,-17.65));
  
  actors.push_back(new Platform(this,0,0,30,400,you));
  actors.push_back(new Platform(this,670,180,30,420,you));
  actors.push_back(new Platform(this,30,0,670,30,you));
  actors.push_back(new Platform(this,150,180,520,30,you));
  actors.push_back(new Platform(this,30,120,100,30,you));
  actors.push_back(new Platform(this,0,530,120,30,you));
  
}
void Level5::makeEnemies() {
  right_wall = new DeathArea(this,670,30,30,150,you);
  actors.push_back(right_wall);
  actors.push_back(new Follower(this,-10,you->getY1(),you,0,&actors));
}
void Level5::makeCollectables() {
  //Make the hints
  actors.push_back(new Hint(this,30,500,30,you,"RUN you FOOL!;"));
  buildExtra(630,220);
}

void Level5::makeSwitches() {
  //Make the save point
  actors.push_back(new RedSwitch(this,35,85,30,you,RED_1));
}

Level* makeLevel5(You* yo, float x, float y, ENT_CODE ent) {
  return new Level5(yo,x,y,ent);
}


void Level5::act() {
  if (right_wall->getHeight()<150)
    right_wall->setHeight(right_wall->getHeight()+.4);
  Level::act();
}

void Level5::sendEvent(EVE_CODE eve, Actor* sender) {
  if (eve==RED_1) {
    right_wall->setHeight(0);
  }
  else {
    Level::sendEvent(eve,sender);
  }
}

bool Level5::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getX2()<0) {
    next_level=SPLIT;
    ent_type=EAST;
    return true;
  }
  if (you->getX1()>700) {
    next_level=REVERSE;
    ent_type=WEST;
    return true;
  }
  return false;
}
