#include "stdafx.h"
#include "Level14.h"
#include "../Platforms/Platform.h"
#include "../Platforms/ThinPlat.h"
#include "../Switables/Save.h"
#include "../Enemies/Drone.h"
#include "../Enemies/LineDrone.h"
#include "../Platforms/InviPlat.h"
#include <iostream>

Level14::Level14(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  me = RISING_EYE;
  setup();
  if (ent==NORTH) {
    isMove=false;
    you->setPosition(enterx,-18,true);
  }
  else if (ent==SOUTH) {
    you->setPosition(enterx,598,true);
  }
  else if (ent==LOAD_1) {
    you->setPosition(90,460);
  }
  else
    throw THROW_ENTRANCE_ERROR;
  isMove=true;
}

void Level14::makePlatforms() {
  eye = new SmallEye(this,680-35,580+20,you,3);
  actors.push_back(eye);
  actors.push_back(new Platform(this,0,0,30,660,you));
  actors.push_back(new Platform(this,30,-30,500,60,you));
  actors.push_back(new Platform(this,670,-30,30,630,you));
  float h = 60;
  int numPlats =(590-100)/h+1; 
  float w = (670-108.0)/(numPlats);
  for (int i=1;i<=numPlats;i++) 
    actors.push_back(new Platform(this,130+(i-1)*w,590-h*i,w,h*i+30,you));
  actors.push_back(new ThinPlat(this,30,590,100,you));
  /*actors.push_back(new Platform(this,130+w,590-h*2,w,30+h*2,you));
  actors.push_back(new Platform(this,130+w*2,590-h*3,w,30+h*3,you));
  actors.push_back(new Platform(this,130+w*3,590-h*4,w,30+h*4,you));
  actors.push_back(new Platform(this,130+w*4,590-h*5,w,30+h*5,you));
  */
  
}
void Level14::makeEnemies() {
  
}
void Level14::makeCollectables() {
  //Make the hints
  buildExtra(45,45);
}

void Level14::makeSwitches() {
  actors.push_back(new Save(this,80,450,40,you,PRE_BOSS_2));
}

void Level14::makeDetectors() {
  b1 = new BigEye(this,680-35,580,EYE_1,eye);
  detectors.push_back(b1);

}

void Level14::act() {
  Level::act();
  if (isMove) {
    float v = -3;
    eye->shiftY(v);
    b1->shiftY(v);
    if (b1->getY2()<0) { 
      isMove=false;
    }
  }
}

Level* makeLevel14(You* yo, float x, float y, ENT_CODE ent) {
  return new Level14(yo,x,y,ent);
}

void Level14::sendEvent(EVE_CODE eve, Actor* sender) {
  if (eve==EYE_1);
  else {
    Level::sendEvent(eve,sender);
  }
}
bool Level14::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getY2()<0) {
    next_level=CLOUD;
    ent_type=SOUTH;
    return true;
  }
  if (you->getY1()>600) {
    next_level=PUZZLE;
    ent_type=NORTH;
    return true;
  }
  if (you->getX2()<0) {
    next_level=SECRET_1;
    ent_type=EAST;
    return true;
  }
  return Level::isChangeRoom(next_level,ent_type);
}
