#include "stdafx.h"
#include "Secret1.h"
#include "../Platforms/Platform.h"
#include "../Platforms/ThinPlat.h"
#include "../Switables/Save.h"
#include "../Enemies/DeathArea.h"
#include "../Enemies/Drone.h"
#include "../Enemies/LineDrone.h"
#include "../Platforms/InviPlat.h"
#include "../Switables/Portal.h"
#include "../Switables/Coin.h"
#include <iostream>

Secret1::Secret1(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  me = SECRET_1;
  setup();
  isPortal=false;
  if (ent==EAST) {
    you->setPosition(698,entery,true);
  }
  else
    throw THROW_ENTRANCE_ERROR;
}

void Secret1::makePlatforms() {

  actors.push_back(new InviPlat(this,540,370,160,30,you));
  actors.push_back(new InviPlat(this,430,250,110,30,you));
  actors.push_back(new InviPlat(this,510,80,160,30,you));
  actors.push_back(new InviPlat(this,30,190,140,30,you));
  actors.push_back(new InviPlat(this,200,190,90,30,you));
  actors.push_back(new InviPlat(this,220,400,150,30,you));
  actors.push_back(new InviPlat(this,110,530,390,40,you));

  block = new InviPlat(this,80,30,30,60,you);
  actors.push_back(block);
    
}
void Secret1::makeEnemies() {
  actors.push_back(new DeathArea(this,0,0,700,30,you));
  actors.push_back(new DeathArea(this,0,30,30,540,you));
  actors.push_back(new DeathArea(this,0,570,700,30,you));
  actors.push_back(new DeathArea(this,670,30,30,150,you));
  actors.push_back(new DeathArea(this,510,280,30,120,you));
  actors.push_back(new DeathArea(this,460,110,210,40,you));
  actors.push_back(new DeathArea(this,260,220,30,180,you));
  actors.push_back(new DeathArea(this,80,90,30,100,you));
  actors.push_back(new DeathArea(this,140,90,30,100,you));
  actors.push_back(new DeathArea(this,200,90,30,100,you));
  actors.push_back(new DeathArea(this,260,90,30,100,you));
  actors.push_back(new DeathArea(this,510,400,190,30,you));
  actors.push_back(new DeathArea(this,30,220,240,30,you));
  actors.push_back(new DeathArea(this,110,315,30,215,you));
  actors.push_back(new DeathArea(this,370,410,50,50,you));
  
  actors2.push_back(new LineDrone(this,300,35,you,1+8));
  actors2.push_back(new LineDrone(this,455,260,you,3+4));
  actors2.push_back(new LineDrone(this,375,480,you,1+12));

}
void Secret1::makeCollectables() {
  //Make the hints
  buildExtra(640,40);
  collect1=0;
  collect1+=buildCoin(550,340,COLLECT_1);
  collect1+=buildCoin(640,160,COLLECT_1);
  collect1+=buildCoin(120,160,COLLECT_1);
  collect1+=buildCoin(240,160,COLLECT_1);
  collect1+=buildCoin(480,290,COLLECT_1);
  collect1+=buildCoin(300,370,COLLECT_1);
  collect1+=buildCoin(640,530,COLLECT_1);
  collect1+=buildCoin(230,260,COLLECT_1);
  collect1+=buildCoin(60,320,COLLECT_1);

}

void Secret1::makeSwitches() {
  actors.push_back(new Portal(this,50,430,30,120,you,PORTALE_1));
}

void Secret1::makeDetectors() {
  detectors.push_back(new Detector(this,0,0,30,600,&actors2));

  detectors.push_back(new Detector(this,670,0,30,600,&actors2));
}


Level* makeSecret1(You* yo, float x, float y, ENT_CODE ent) {
  return new Secret1(yo,x,y,ent);
}

void Secret1::sendEvent(EVE_CODE eve, Actor* sender) {
  if (eve==COLLECT_1) {
    collect1--;
    remove(sender);
  }
  else if (eve==PORTALE_1) {
    isPortal=true;
  }
  else {
    Level::sendEvent(eve,sender);
  }
  if (collect1<=0&&block) {
    remove(block);block=NULL;
  }
}
bool Secret1::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getX1()>700) {
    next_level=RISING_EYE;
    ent_type=WEST;
    return true;
  }
  if (isPortal) {
    next_level=RISING_EYE;
    ent_type=PORTAL_1;
    //GFD better keep track of fairy (across rooms)
    if (gotFairy)
      ent_type=PORTAL_2;
    return true;
  }
  return Level::isChangeRoom(next_level,ent_type);
}
