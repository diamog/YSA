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
    you->setPosition(60,110);
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
  actors.push_back(new Platform(this,0,0,700,30,you));
  actors.push_back(new ThinPlat(this,30,580,640,you));
  actors.push_back(new Platform(this,0,30,30,570,you));
  actors.push_back(new Platform(this,670,150,30,450,you));
  actors.push_back(new Platform(this,30,510,400,30,you));
  actors.push_back(new ThinPlat(this,30,430,70,you));
  actors.push_back(new ThinPlat(this,30,360,70,you));
  actors.push_back(new ThinPlat(this,30,290,70,you));
  actors.push_back(new ThinPlat(this,30,220,70,you));
  actors.push_back(new Platform(this,130,160,80,30,you));
  actors.push_back(new Platform(this,230,270,80,30,you));
  actors.push_back(new Platform(this,300,30,30,120,you));
  actors.push_back(new Platform(this,550,30,30,100,you));
  actors.push_back(new ThinPlat(this,450,127,100,you));
  
}
void Level4::makeEnemies() {
  actors.push_back(new DeathArea(this,30,540,400,40,you));
  actors.push_back(new DeathArea(this,200,300,470,40,you));
}
void Level4::makeCollectables() {
  //Make the hints
  //actors.push_back(new Hint(this,440,540,30,you,"Becareful these red portions will kill you!;"));
  buildExtra(635,345);
}

void Level4::makeSwitches() {
  //Make the save point 
  actors.push_back(new Save(this,50,100,40,you,CROSS_ROADS));
}


Level* makeLevel4(You* yo, float x, float y, ENT_CODE ent) {
  return new Level4(yo,x,y,ent);
}

bool Level4::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getY1()>600) {
    next_level=START;
    ent_type=NORTH;
    return true;
  }
  if (you->getX1()>700) {
    next_level=MOVING;
    ent_type=WEST;
    return true;
  }
  return false;
}
