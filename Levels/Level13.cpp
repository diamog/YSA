#include "stdafx.h"
#include "../Extras/utilities.h"
#include "Level13.h"
#include "../Platforms/Platform.h"
#include "../Platforms/ThinPlat.h"
#include "../Platforms/Button.h"
#include "../Switables/Save.h"
#include "../Enemies/Drone.h"
#include "../Enemies/LineDrone.h"
#include "../Platforms/InviPlat.h"
#include <iostream>

Level13::Level13(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  me = PUZZLE;
  setup();
  isMove=true;
  if (ent==NORTH) {
    you->setPosition(enterx,-18,true);
    sendEvent(EYE_2,NULL);
    isMove=false;
    b1->shiftY(30);
    b2->shiftY(-200);
  }
  else if (ent==SOUTH) {
    you->setPosition(enterx,598,true);
  }
  else if (ent==LOAD_1) {
    you->setPosition(370,410);
  }
  else
    throw THROW_ENTRANCE_ERROR;
}

void Level13::makePlatforms() {
  eye = new SmallEye(this,680-35,580+20,you,3);
  actors.push_back(eye);
  actors.push_back(new Platform(this,250,450,30,180,you));
  actors.push_back(new Platform(this,500,450,30,180,you));
  actors.push_back(new ThinPlat(this,280,590,220,you));
  actors.push_back(new Platform(this,0,450,250,30,you));
  actors.push_back(new Platform(this,0,-30,30,480,you));
  ceiling = new Platform(this,30,-30,640,60,you);
  actors.push_back(ceiling);
  actors.push_back(new Platform(this,530,450,170,30,you));
  actors.push_back(new Platform(this,670,0,30,450,you));

  actors.push_back(new Button(this,520,430,you,PURPLE));
  actors.push_back(new Button(this,600,430,you,ORANGE));
  actors.push_back(new Button(this,200,430,you,GREEN));
}

void Level13::makeCollectables() {
  //Make the hints
  buildSave(360,400,PUZZLE_EASY,EASY);
  buildExtra(530,40);
}

void Level13::makeDetectors() {
  b1 = new BigEye(this,680-35,580,EYE_3,eye);
  detectors.push_back(b1);
  b2 = new BigEye(this,680-35,70,EYE_2,eye);
  detectors.push_back(b2);
  pblock1 = new Block(this,40,360,0,eye,you,3);
  gblock1 = new Block(this,40,70,1,eye,you,3);
  pblock2 = new Block(this,300,70,0,eye,you,2);
  gblock2 = new Block(this,300,250,1,eye,you,3);
  pblock3 = new Block(this,500,70,0,eye,you,2);
  gblock3 = new Block(this,500,250,1,eye,you,2);
  detectors.push_back(pblock1);
  detectors.push_back(gblock1);
  detectors.push_back(pblock2);
  detectors.push_back(gblock2);
  detectors.push_back(pblock3);
  detectors.push_back(gblock3);
  
  owall1 = new Wall(this,30,250,150,30,eye,you,true);
  owall2 = new Wall(this,200,30,30,150,eye,you,false);
  owall3 = new Wall(this,425,30,30,150,eye,you,true);
  detectors.push_back(owall1);
  detectors.push_back(owall2);
  detectors.push_back(owall3);
}

void Level13::act() {
  Level::act();
  if (isMove) {
    float v = -1;
    eye->shiftY(v);
    if (b1->isOn()) {
      b1->shiftY(v);
      if (b1->getY2()<430) 
	sendEvent(EYE_1,NULL);
    }
    else if (b2->isOn()) {
      b2->shiftY(v*3);
      eye->shiftY(v*2);
    }
  }
}

Level* makeLevel13(You* yo, float x, float y, ENT_CODE ent) {
  return new Level13(yo,x,y,ent);
}

void Level13::sendEvent(EVE_CODE eve, Actor* sender) {
  if (eve==EYE_2) {
    isMove=true;
    ceiling->setPosition(130,-30);
  }
  else if (eve==EYE_1) {
    isMove=false;
    float ex,ey;
    getObjectCenter(eye,ex,ey);
    eye->setReset(ex,ey);
    actors.push_back(new RedSwitch(this,465,550,30,you,RED_1));
  }
  else if (eve==EYE_3) {
    eye->setDir(3);
  }
  else if (eve==RED_1) {
    if (b1->isOn()) {
      eye->start();
    }
  }
  else if (eve==GREEN) {
    gblock1->rotate(1);
    gblock2->rotate(1);
    gblock3->rotate(1);
  }
  else if (eve==PURPLE) {
    pblock1->rotate(-1);
    pblock2->rotate(-1);
    pblock3->rotate(-1);
  }
  else if (eve==ORANGE) {
    owall1->turn();
    owall2->turn();
    owall3->turn();
  }
  else {
    Level::sendEvent(eve,sender);
  }
}
bool Level13::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getY2()<0) {
    next_level=PREBOSS2;
    ent_type=SOUTH;
    return true;
  }
  if (you->getY1()>600) {
    next_level=RISING_EYE;
    ent_type=NORTH;
    return true;
  }
  return Level::isChangeRoom(next_level,ent_type);
}
