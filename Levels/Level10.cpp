#include "stdafx.h"
#include "Level10.h"
#include "../Enemies/DeathArea.h"
#include <iostream>

Level10::Level10(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  me = FALL;
  height=1800;
  setup();
  if (ent== SOUTH) {
    you->setPosition(enterx-700,598,true);
  }
  else if (ent==NORTH) {
    you->setPosition(enterx,-18,true);
  }
  else
    throw THROW_ENTRANCE_ERROR;
}


void Level10::makeEnemies() {
  actors.push_back(new DeathArea(this,255,0,30,height,you));
  actors.push_back(new DeathArea(this,425,0,30,height,you));

  actors.push_back(new DeathArea(this,285,200,55,40,you));
  actors.push_back(new DeathArea(this,370,350,55,40,you));
  actors.push_back(new DeathArea(this,285,450,40,40,you));
  actors.push_back(new DeathArea(this,340,600,40,40,you));
  actors.push_back(new DeathArea(this,340,640,85,40,you));
  actors.push_back(new DeathArea(this,285,800,85,40,you));

  actors.push_back(new DeathArea(this,330,940,40,40,you));
  actors.push_back(new DeathArea(this,285,1050,55,40,you));
  actors.push_back(new DeathArea(this,370,1200,55,40,you));
  actors.push_back(new DeathArea(this,340,1320,55,40,you));
  actors.push_back(new DeathArea(this,285,1500,50,40,you));
  actors.push_back(new DeathArea(this,375,1500,50,40,you));

  actors.push_back(new DeathArea(this,340,1760,85,40,you));
  

}
void Level10::makeCollectables() {
  buildExtra(395,1320);
}

void Level10::act() {
  float diff = you->getY1()-you->getLastY1();
  if (diff>5)
    you->shiftY(5-diff);
  Level::act();
}

Level* makeLevel10(You* yo, float x, float y, ENT_CODE ent) {
  return new Level10(yo,x,y,ent);
}

bool Level10::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getY2()<0) {
    next_level=SPLIT;
    ent_type=SOUTH;
    return true;
  }
  if (you->getY1()>600) {
    next_level=EYE;
    ent_type=NORTH;
    you->setFall(5);
    return true;
  }
  return Level::isChangeRoom(next_level,ent_type);

}
