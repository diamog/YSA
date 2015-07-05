#include "stdafx.h"
#include "Level6.h"
#include "../Platforms/Platform.h"
#include "../Platforms/ThinPlat.h"
#include "../Switables/Save.h"
#include "../Enemies/DeathArea.h"
#include "../Switables/RedSwitch.h"
#include "../Enemies/Reverser.h"
#include <iostream>

Level6::Level6(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  me = REVERSE;
  height=1060;
  if (ent== WEST) {
    you->setPosition(-18,entery,true);
  } 
  else if(ent==EAST) {
    you->setPosition(698,entery,true);
  }
  else if (ent==LOAD_1) {
    you->setPosition(110,90);
  }
  else
    throw THROW_ENTRANCE_ERROR;
  rev = new Reverser(this,you,true);
  actors.push_back(rev);
  setup();
  for (unsigned int i=0;i<actors.size();i++)
    if (actors[i]!=rev)
    actors[i]->addReverser(rev);
  
}


void Level6::makePlatforms() {
  
  actors.push_back(new Platform(this,0,0,700,30,you));
  room_split=new Platform(this,335,30,30,1000,you);
  actors.push_back(room_split);
  actors.push_back(new Platform(this,0,180,30,990,you));
  actors.push_back(new Platform(this,670,180,30,990,you));
  actors.push_back(new Platform(this,30,180,230,30,you));
  actors.push_back(new Platform(this,440,180,230,30,you));
  actors.push_back(new Platform(this,365,80,60,30,you));
  actors.push_back(new Platform(this,155,280,230,30,you));
  actors.push_back(new Platform(this,365,280,230,30,you));
  actors.push_back(new Platform(this,105,250,50,60,you));
  actors.push_back(new Platform(this,440,180,50,60,you));
  actors.push_back(new Platform(this,30,380,230,30,you));
  actors.push_back(new Platform(this,440,380,230,30,you));
  actors.push_back(new ThinPlat(this,125,480,210,you));
  actors.push_back(new ThinPlat(this,365,480,210,you));
  actors.push_back(new Platform(this,30,550,230,100,you));
  actors.push_back(new Platform(this,440,550,230,30,you));
  //Second Half of things
  actors.push_back(new Platform(this,440,620,230,30,you));
  left_block = new Platform(this,30,690,305,30,you);
  right_block = new Platform(this,365,690,305,30,you);
  actors.push_back(left_block);
  actors.push_back(right_block);
  actors.push_back(new Platform(this,135,820,30,40,you));
  actors.push_back(new Platform(this,165,860,40,30,you));
  actors.push_back(new Platform(this,30,960,130,30,you));
  
  actors.push_back(new Platform(this,365,820,50,30,you));
  actors.push_back(new Platform(this,610,780,60,30,you));
  actors.push_back(new Platform(this,540,960,230,30,you));

  actors.push_back(new Platform(this,0,1030,700,30,you));
}
void Level6::makeEnemies() {
  floor_block= new DeathArea(this,30,490,305,30,you);
  actors.push_back(floor_block);
  actors.push_back(new DeathArea(this,165,790,40,30,you));
  actors.push_back(new DeathArea(this,205,820,30,40,you));
  falling_skies = new DeathArea(this,0,-30,700,30,you);
  actors.push_back(falling_skies);
}
void Level6::makeCollectables() {
  //Make the hints
  extra=NULL;
  if (!you->hasExtra(me)) {
    extra = new Extra(this,0,-30,25,25,you);
    actors.push_back(extra);
  }
}

void Level6::makeSwitches() {
  //Make the save point
  actors.push_back(new Save(this,100,80,40,you,REVERSE_ROOM));
  actors.push_back(new RedSwitch(this,300,35,30,you,RED_1));
  actors.push_back(new RedSwitch(this,370,35,30,you,RED_1));
  actors.push_back(new RedSwitch(this,35,655,30,you,RED_2));
  actors.push_back(new RedSwitch(this,635,585,30,you,RED_2));
  
  actors.push_back(new RedSwitch(this,35,925,30,you,RED_4));
  actors.push_back(new RedSwitch(this,300,995,30,you,RED_3));
  actors.push_back(new RedSwitch(this,170,825,30,you,RED_5));

  actors.push_back(new RedSwitch(this,635,745,30,you,RED_4));
  actors.push_back(new RedSwitch(this,370,785,30,you,RED_3));
  actors.push_back(new RedSwitch(this,635,995,30,you,RED_5));
  
}

Level* makeLevel6(You* yo, float x, float y, ENT_CODE ent) {
  return new Level6(yo,x,y,ent);
}


void Level6::act() {
  if (floor_block->getX1()>30) {
    float rate=.5;
    floor_block->setWidth(floor_block->getWidth()+rate);
    floor_block->setPosition(floor_block->getX1()-rate,490);
  }
  else
    floor_block->setPosition(30,490);
  
  if (falling_skies->getY1()+y>=0)
    falling_skies->shiftY(10);
  count1=0;
  count2=0;
  count3=0;
  count4=0;
  count5=0;
  Level::act();
}

void Level6::sendEvent(EVE_CODE eve, Actor* sender) {
  if (eve==RED_1) {
    count1++;
  }
  else if (eve==RED_2) 
    count2++;
  else if (eve==RED_3)
    count3++;
  else if (eve==RED_4)
    count4++;
  else if (eve==RED_5)
    count5++;
  else {
    Level::sendEvent(eve,sender);
  }
  if (count2==2) {
    left_block->setPosition(60,690);
    right_block->setWidth(275);
  }
  if (count1==2) {
    floor_block->setWidth(1);
    floor_block->setPosition(334,490);
  }
  if (count3==2) {
    room_split->setHeight(950);
  }
  if (count4==2) {
    falling_skies->setPosition(0,0);
  }
  if (count5==2&&extra!=NULL) {
    extra->setPosition(350-25.0/2,1000-25.0/2);
  }
}

bool Level6::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getX2()<0) {
    next_level=FOLLOW;
    ent_type=EAST;
    return true;
  }
  if (you->getX1()>700) {
    next_level=KICK;
    ent_type=WEST;
    return true;
  }
  return false;
}
