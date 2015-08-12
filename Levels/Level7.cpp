#include "stdafx.h"
#include "Level7.h"
#include "../Platforms/Platform.h"
#include "../Platforms/KickPlat.h"
#include "../Switables/Save.h"
#include "../Enemies/DeathArea.h"
#include "../Switables/RedSwitch.h"
#include "../Enemies/Reverser.h"
#include "../Enemies/Drone.h"
#include "../Enemies/Rider.h"
#include <iostream>

Level7::Level7(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  me = KICK;
  if (ent==WEST) {
    you->setPosition(-18,entery,true);
  } 
  else if(ent==NORTH) {
    you->setPosition(enterx,-18,true);
  }
  else if (ent==LOAD_1) {
    you->setPosition(340,410);
  }
  else
    throw THROW_ENTRANCE_ERROR;
  setup();
}


void Level7::makePlatforms() {
  //left side
  actors.push_back(new Platform(this,0,0,220,30,you));
  actors.push_back(new Platform(this,0,180,30,570-180,you));

 
  //middle
  actors.push_back(new KickPlat(this,220,-30,30,480,you,false,true));
  actors.push_back(new KickPlat(this,450,-30,30,480,you,true,true));
  actors.push_back(new Platform(this,0,570,700,30,you));

 //right side
  actors.push_back(new KickPlat(this,670,30,30,540,you,true,false));
  actors.push_back(new Platform(this,480,0,220,30,you));

}
void Level7::makeEnemies() {
  actors2.push_back(new Drone(this,480,200,you,0));
  actors2.push_back(new Drone(this,640,200,you,2));
  actors2.push_back(new Rider(this,350,570-35,you,1));
}
void Level7::makeCollectables() {
  //Make the hints
  buildHint(335,540,10,"You can wall jump off notched walls by pressing the jump button.; You also regain your double jump after wall jumping.;");
  buildExtra(635,35);
}

void Level7::makeSwitches() {
  //Make the save point
  buildSave(330,400,PRE_WALL_KICK,HARD);
}
void Level7::makeDetectors() {
  detectors.push_back(new Detector(this,470,20,30,30,&actors2));
  detectors.push_back(new Detector(this,460,430,30,30,&actors2));
  detectors.push_back(new Detector(this,660,30,30,30,&actors2));
  detectors.push_back(new Detector(this,650,440,30,30,&actors2));
  detectors.push_back(new Detector(this,670,570-30,30,30,&actors2));
  detectors.push_back(new Detector(this,0,570-30,30,30,&actors2));
}

Level* makeLevel7(You* yo, float x, float y, ENT_CODE ent) {
  return new Level7(yo,x,y,ent);
}




bool Level7::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getX2()<0) {
    next_level=REVERSE;
    ent_type=EAST;
    return true;
  }
  if (you->getY2()<0) {
    next_level=CLIMB;
    ent_type=SOUTH;
    return true;
  }
  return Level::isChangeRoom(next_level,ent_type);

}
