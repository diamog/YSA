#include "stdafx.h"
#include "Level12.h"
#include "../Platforms/Platform.h"
#include "../Platforms/ThinPlat.h"
#include "../Switables/Save.h"
#include "../Enemies/Drone.h"
#include "../Enemies/LineDrone.h"
#include "../Platforms/InviPlat.h"
#include <iostream>

Level12::Level12(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  me = RISING_EYE;
  setup();
  isMove=true;
  if (ent==NORTH) {
    you->setPosition(enterx,-18,true);
    isMove=false;
    b1->shiftY(30);
  }
  else if (ent==SOUTH) {
    you->setPosition(enterx,598,true);
  }
  else if (ent==WEST) {
    you->setPosition(-18,entery,true);
    isMove=false;
    b1->shiftY(30);
  }
  else if (ent==LOAD_1) {
    you->setPosition(380,460);
  }
  else if (ent==PORTAL_1) {
    you->setPosition(380,460);
  }
  else if (ent==PORTAL_2) {
    you->setPosition(380,460);
    //DO stuff with fairy
  }
  else
    throw THROW_ENTRANCE_ERROR;
}

void Level12::makePlatforms() {
  eye = new SmallEye(this,680-35,580+20,you,3);
  actors.push_back(eye);
  middle = new Platform(this,250,-30,30,660,you);
  actors.push_back(middle);
  actors.push_back(new Platform(this,500,-30,30,660,you));
  actors.push_back(new ThinPlat(this,280,590,220,you));
  actors.push_back(new ThinPlat(this,280,400,60,you));
  actors.push_back(new ThinPlat(this,440,495,60,you));
  actors.push_back(new ThinPlat(this,280,300,220,you));
  actors.push_back(new ThinPlat(this,280,210,60,you));
  actors.push_back(new ThinPlat(this,350,120,60,you));
  actors.push_back(new ThinPlat(this,280,30,220,you));

  actors.push_back(new InviPlat(this,0,150,250,30,you));
  actors.push_back(new InviPlat(this,0,370,250,30,you));
  actors.push_back(new InviPlat(this,0,570,250,30,you));
}
void Level12::makeEnemies() {
  
  actors2.push_back(new LineDrone(this,295,300,you,8));
  actors2.push_back(new LineDrone(this,455,200,you,6));
  actors2.push_back(new LineDrone(this,375,400,you,4));

}
void Level12::makeCollectables() {
  //Make the hints
  buildExtra(220,500);
}

void Level12::makeSwitches() {
  actors.push_back(new Save(this,370,450,40,you,THIN_EYE));
  
}

void Level12::makeDetectors() {
  detectors.push_back(new Detector(this,280,-30,300,30,&actors2));

  detectors.push_back(new Detector(this,280,580,300,30,&actors2));


  b1 = new BigEye(this,680-35,580,NOTHING,eye);
  detectors.push_back(b1);

}

void Level12::act() {
  Level::act();
  if (isMove) {
    float v = -1;
    eye->shiftY(v);
    b1->shiftY(v);
    if (b1->getY2()<0) 
      sendEvent(EYE_1,NULL);
  }
}

Level* makeLevel12(You* yo, float x, float y, ENT_CODE ent) {
  return new Level12(yo,x,y,ent);
}

void Level12::sendEvent(EVE_CODE eve, Actor* sender) {
  if (eve==EYE_1) {
    isMove=false;
    remove(middle);
    actors.push_back(new Platform(this,250,370,30,230,you));
    actors.push_back(new Platform(this,250,-30,30,210,you));
  }
  else {
    Level::sendEvent(eve,sender);
  }
}
bool Level12::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getY2()<0) {
    next_level=PUZZLE;
    ent_type=SOUTH;
    return true;
  }
  if (you->getY1()>600) {
    next_level=EYE;
    ent_type=MISC_1;
    return true;
  }
  if (you->getX2()<0) {
    next_level=SECRET_1;
    ent_type=EAST;
    return true;
  }
  return Level::isChangeRoom(next_level,ent_type);
}
