#include "stdafx.h"
#include "Level4.h"
#include "../Platforms/Platform.h"
#include "../Platforms/ThinPlat.h"
#include "../Switables/Hint.h"
#include "../Switables/Save.h"
#include "../Enemies/DeathArea.h"
#include <iostream>

Level4::Level4(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  setup();
  me = SPLIT;
  if (ent== SOUTH) {
    you->setPosition(enterx,598);
		
  }
  else if (ent== LOAD_1) {
    //Load into savepoint 1
    you->setPosition(610,120);
    //you->setPosition(610,500);
  } 
  else if(ent==EAST) {
    you->setPosition(698,entery);
  }
  else if (ent==NORTH) {
    you->setPosition(enterx,-18);
  }
  else
    throw THROW_ENTRANCE_ERROR;
}


void Level4::makePlatforms() {
  actors.push_back(new Platform(this,0,0,30,600,you));
  actors.push_back(new Platform(this,670,0,30,400,you));
  actors.push_back(new Platform(this,30,80,500,40,you));
  actors.push_back(new Platform(this,170,250,500,50,you));
  actors.push_back(new Platform(this,275,380,150,30,you));
  actors.push_back(new Platform(this,30,500,225,30,you));
  actors.push_back(new Platform(this,450,500,150,30,you));
  actors.push_back(new Platform(this,600,530,100,30,you));
  
}
void Level4::makeEnemies() {
  actors.push_back(new DeathArea(this,480,120,50,50,you));
  actors.push_back(new DeathArea(this,170,200,60,50,you));
  actors.push_back(new DeathArea(this,30,120,60,70,you));
  actors.push_back(new DeathArea(this,120,250,50,80,you));
  actors.push_back(new DeathArea(this,30,380,80,60,you));
  actors.push_back(new DeathArea(this,375,340,50,40,you));
  actors.push_back(new DeathArea(this,490,300,30,80,you));
  actors.push_back(new DeathArea(this,570,400,100,30,you));
  actors.push_back(new DeathArea(this,255,530,30,70,you));
  actors.push_back(new DeathArea(this,420,530,30,70,you));
  actors.push_back(new DeathArea(this,285,570,135,30,you)); //TO BE REMOVED

}
void Level4::makeCollectables() {
  //Make the hints
  //actors.push_back(new Hint(this,440,540,30,you,"Becareful these red portions will kill you!;"));
  buildExtra(630,310);
}

void Level4::makeSwitches() {
  //Make the save point 
  actors.push_back(new Save(this,600,110,40,you,CROSS_ROADS));
}


Level* makeLevel4(You* yo, float x, float y, ENT_CODE ent) {
  return new Level4(yo,x,y,ent);
}

bool Level4::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getY2()<0) {
    next_level=COLOR;
    ent_type=SOUTH;
    return true;
  }
  if (you->getY1()>600) {
    next_level=FALL;
    ent_type=NORTH;
    return true;
  }
  if (you->getX1()>700) {
    next_level=FOLLOW;
    ent_type=WEST;
    return true;
  }
  return false;
}
