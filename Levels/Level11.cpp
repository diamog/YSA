#include "stdafx.h"
#include "Level11.h"
#include "../Enemies/DeathArea.h"
#include "../Platforms/Platform.h"
#include "../Platforms/ThinPlat.h"
#include "../Switables/Save.h"
#include "../Enemies/Drone.h"
#include "../Enemies/LineDrone.h"
#include "../Platforms/Button.h"
#include <iostream>

Level11::Level11(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  me = EYE;
  width=1400;
  setup();
  if (ent==NORTH) {
    you->setPosition(enterx,-18,true);
    x=700;
    canMove=false;
  }
  else if (ent==MISC_1) {
    you->setPosition(enterx,-18,true);
    sendEvent(EYE_3,NULL);
    b3->shiftY(-300);
  }
  else if (ent==LOAD_1) {
    you->setPosition(1050-700,360);
    canMove=false;
    
    x=700;
  }
  else
    throw THROW_ENTRANCE_ERROR;
  isMove=false;
  isR1=isR2=isR3=false;
  canMove=true;
}

void Level11::makePlatforms() {
  eye = new SmallEye(this,1335,480+35,you,3);
  actors.push_back(eye);
  actors.push_back(new Platform(this,0,570,1400,30,you));
  actors.push_back(new Platform(this,0,0,30,570,you));
  middle = new Platform(this,685,0,30,570,you);
  actors.push_back(middle);
  actors.push_back(new Platform(this,1370,0,30,570,you));
  actors.push_back(new Platform(this,715,0,240,30,you));
  actors.push_back(new Platform(this,700+425+30,0,width-60-700-425,30,you));
  actors.push_back(new Platform(this,700+255-90,320,90,30,you));
  actors.push_back(new Platform(this,715,400,90,30,you));
  actors.push_back(new Platform(this,700+255-90,320-80*2,90,30,you));
  actors.push_back(new Platform(this,715,320-80,90,30,you));
  actors.push_back(new Platform(this,715,320-80*3,90,30,you));
  float diff = 90;
  actors.push_back(new ThinPlat(this,1300,450,70,you));
  actors.push_back(new ThinPlat(this,1300,450-diff,70,you));
  actors.push_back(new ThinPlat(this,1300,450-diff*2,70,you));
  actors.push_back(new ThinPlat(this,1300,450-diff*3,70,you));
  actors.push_back(new ThinPlat(this,1300,450-diff*4,70,you));

  //Left Side
  actors.push_back(new Platform(this,30,0,220,30,you));
  actors.push_back(new Platform(this,250,-30,30,383,you));
  actors.push_back(new Platform(this,500,-30,30,383,you));
  
  actors.push_back(new ThinPlat(this,30,450,50,you));
  actors.push_back(new ThinPlat(this,200,350,50,you));
  actors.push_back(new ThinPlat(this,30,250,50,you));
  actors.push_back(new Platform(this,30,80,100,30,you));
  
  actors.push_back(new ThinPlat(this,200,130,50,you));

  actors.push_back(new Button(this,250,550,you,PURPLE));
  actors.push_back(new Button(this,150,550,you,GREEN));
}
void Level11::makeEnemies() {
  actors.push_back(new DeathArea(this,700+255,0,30,350,you));
  actors.push_back(new DeathArea(this,700+425,0,30,350,you));

  actors2.push_back(new Drone(this,1360,250,you,-(2+8)));
  actors2.push_back(new Drone(this,1200,30,you,-(1+8)));
  actors2.push_back(new LineDrone(this,810,200,you,4));
  actors2.push_back(new LineDrone(this,810,200,you,2));

  actors2.push_back(new LineDrone(this,50,130,you,5));
  actors2.push_back(new LineDrone(this,120,270,you,3));

  
}
void Level11::makeCollectables() {
  //Make the hints
  buildExtra(700+380,50);
}

void Level11::makeSwitches() {
  buildSave(1040,350,BOTTOM_PIT,MEDIUM);
  //Wuss save point on left side
  r1= new RedSwitch(this,730,45,30,you,RED_1);
  actors.push_back(r1);
  r2=new RedSwitch(this,1335,45,30,you,RED_2);
  actors.push_back(r2);
  r3=new RedSwitch(this,35,45,30,you,RED_3);
  actors.push_back(r3);
  
}

void Level11::makeDetectors() {
  detectors.push_back(new Detector(this,810,0,30,30,&actors2));
  detectors.push_back(new Detector(this,810,430,30,30,&actors2));
  detectors.push_back(new Detector(this,1350,0,30,30,&actors2));
  detectors.push_back(new Detector(this,1350,440,30,30,&actors2));
  detectors.push_back(new Detector(this,700+425+20,10,30,30,&actors2));
  detectors.push_back(new Detector(this,700+425+20,450,30,30,&actors2));
  
  //left side
  detectors.push_back(new Detector(this,0,130,30,300,&actors2));
  detectors.push_back(new Detector(this,250,130,30,300,&actors2));

  b1 = new BigEye(this,1335,490,EYE_1,eye);
  detectors.push_back(b1);
  b2 = new BigEye(this,-5,490,EYE_2,eye);
  detectors.push_back(b2);
  b3 = new BigEye(this,680-35,150,EYE_3,eye);
  detectors.push_back(b3);

  pblock= new Block(this,560,480,0,eye,you,3);
  detectors.push_back(pblock);
  gblock= new Block(this,560,140,1,eye,you,0);
  detectors.push_back(gblock);

}

void Level11::act() {
  Level::act();
  if (isMove) {
    float v = -2;
    eye->shiftY(v);
    b3->shiftY(v);
  }
}

Level* makeLevel11(You* yo, float x, float y, ENT_CODE ent) {
  return new Level11(yo,x,y,ent);
}

void Level11::sendEvent(EVE_CODE eve, Actor* sender) {
  if (eve==RED_1) {
    isR1=true;
    sender->setColor(0,255,0);
  }
  else if (eve==RED_2) {
    sender->setColor(0,255,0);
    isR2=true;
  }
  else if (eve==RED_3) {
    isR3=true;
    sender->setColor(0,255,0);
  }
  else if (eve==EYE_1) {
    eye->setDir(3);
  }
  else if (eve==EYE_2) {
    canMove=true;
    middle->setHeight(500);
    eye->setDir(1);
  }
  else if (eve==EYE_3) {
    //make platforms
    eye->setDir(-1);
    float diff=85;
    actors.push_back(new ThinPlat(this,280,350,50,you));
    actors.push_back(new ThinPlat(this,280,350-diff,50,you));
    actors.push_back(new ThinPlat(this,280,350-diff*2,50,you));
    actors.push_back(new ThinPlat(this,280,350-diff*3,50,you));
    isMove=true;
  }
  else if (eve==GREEN) {
    gblock->rotate(1);
  }
  else if (eve==PURPLE) {
    pblock->rotate(-1);
  }
  else
    Level::sendEvent(eve,sender);
  if (isR1&&isR2&&b1->isOn()) {
    eye->start();
  }
  if (isR3&&b2->isOn()) {
    eye->start();
  }
}
bool Level11::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getY2()<0&&x>400) {
    next_level=FALL;
    ent_type=SOUTH;
    return true;
  }
  if (you->getY2()<0) {
    next_level=RISING_EYE;
    ent_type=SOUTH;
    return true;
  }
  return Level::isChangeRoom(next_level,ent_type);
}

void Level11::resetEye() {
  isR1=isR2=isR3=false;
  r1->setColor(255,0,0);
  r2->setColor(255,0,0);
  r3->setColor(255,0,0);
}
