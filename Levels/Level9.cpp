#include "stdafx.h"
#include "Level9.h"
#include "../Switables/Coin.h"
#include "../Platforms/Platform.h"
#include "../Platforms/KickPlat.h"
#include "../Switables/Save.h"
#include "../Enemies/DeathArea.h"
#include "../Enemies/Drone.h"
#include "../Enemies/Rider.h"
#include "../Switables/AntiGravity.h"
#include "../Switables/FollowerFactory.h"
#include <iostream>

Level9::Level9(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  me = COLLECTOR;
  height=930;
  width=3450;
  floor=NULL;
  setup();
  if (ent==EAST) {
    you->setPosition(width-2,entery,true);
  } 
  else if (ent==WEST) {
    you->setPosition(-18,(entery-30)+800,true);
  }
  else if(ent==SOUTH) {
    you->setPosition(enterx,height-2,true);
  }
  else if (ent==LOAD_1) {
    you->setPosition(1310,710);
  }
  else if (ent==LOAD_2) {
    you->setPosition(2390,790);
  }
  else if (ent==LOAD_3) {
    you->setPosition(3310,210);
  }
  else if (ent==LOAD_4) 
    you->setPosition(765,790);
  else
    throw THROW_ENTRANCE_ERROR;
}


void Level9::makePlatforms() {
  //Top of wall kicking
  actors.push_back(new Platform(this,0,900,200,30,you));
  actors.push_back(new Platform(this,0,0,width,30,you));
  actors.push_back(new KickPlat(this,0,30,30,770,you,false,true));
  actors.push_back(new KickPlat(this,170,230,30,670,you,true,true));
  actors.push_back(new KickPlat(this,365,30,30,600,you,true,true));
  actors.push_back(new KickPlat(this,560,400,40,530,you,true,true));
  actors.push_back(new KickPlat(this,560,300,40,50,you,true,true));
  actors.push_back(new KickPlat(this,560,200,40,50,you,true,true));
  actors.push_back(new KickPlat(this,750,30,50,720,you,true,true));
  actors.push_back(new KickPlat(this,900,290,30,60,you,false,true));
  floor = new Platform(this,600,700,150,50,you);
  actors.push_back(floor);
  actors.push_back(new KickPlat(this,900,80,30,50,you,false,true));
  
  wall1 = new KickPlat(this,1200,30,50,870,you,true,true);
  actors.push_back(wall1);
  
  wall2 = new KickPlat(this,2250,30,50,870,you,true,true);
  actors.push_back(wall2);

  float start3x=2300;
  actors.push_back(new KickPlat(this,start3x+200,180,30,720,you,true,true));
  actors.push_back(new KickPlat(this,start3x+430,30,30,720,you,true,true));
  actors.push_back(new KickPlat(this,start3x+890,130,30,850,you,true,false));
  actors.push_back(new Platform(this,600,900,width-600-260,30,you));
  actors.push_back(new Platform(this,start3x+1120,30,30,930,you));
}
void Level9::makeEnemies() {
  actors.push_back(new DeathArea(this,200,900,360,30,you));
  actors.push_back(new DeathArea(this,560,350,40,50,you));
  actors.push_back(new DeathArea(this,560,250,40,50,you));
  actors.push_back(new DeathArea(this,560,150,40,50,you));
  actors.push_back(new DeathArea(this,560,30,40,50,you));
  actors.push_back(new DeathArea(this,900,500,300,50,you));
  actors.push_back(new DeathArea(this,900,250,30,40,you));
  actors.push_back(new DeathArea(this,1050,70,150,30,you));
  actors.push_back(new DeathArea(this,900,30,30,50,you));
  actors.push_back(new DeathArea(this,1050,250,30,100,you));
  actors2.push_back(new Drone(this,150,30,you,1));
  actors2.push_back(new Drone(this,365,870,you,-7));
  actors2.push_back(new Drone(this,605,450,you,8));
  actors2.push_back(new Rider(this,900,865,you,-1));

  //Part 2
  float start2x=1250;
  actors.push_back(new DeathArea(this,start2x+150,170,300,30,you));
  actors.push_back(new DeathArea(this,start2x+225,300,50,50,you));
  actors.push_back(new DeathArea(this,start2x+275,350,50,50,you));
  actors.push_back(new DeathArea(this,start2x+325,300,50,50,you));
  actors.push_back(new DeathArea(this,start2x+225,480,30,130,you));
  actors.push_back(new DeathArea(this,start2x+400,600,75,300,you));
  actors.push_back(new DeathArea(this,start2x+525,600,75,300,you));
  actors.push_back(new DeathArea(this,start2x+675,680,225,70,you));
  actors.push_back(new DeathArea(this,start2x+920,30,30,50,you));
  actors.push_back(new DeathArea(this,start2x+920-150,30,30,120,you));
  actors.push_back(new DeathArea(this,start2x+800,350,50,70,you));
  actors.push_back(new DeathArea(this,start2x+800,490,50,70,you));
  actors.push_back(new DeathArea(this,start2x+500,250,70,60,you));
  actors.push_back(new DeathArea(this,start2x+640,250,70,150,you));
  actors.push_back(new DeathArea(this,start2x+500,250+150,210,30,you));
  actors2.push_back(new Rider(this,1400,865,you,1));
  
  //Part 3
  float start3x=2300;
  actors.push_back(new DeathArea(this,start3x+230,180,100,60,you));
  actors.push_back(new DeathArea(this,start3x+330,350,100,60,you));
  actors.push_back(new DeathArea(this,start3x+230,520,100,60,you));
  actors.push_back(new DeathArea(this,start3x+330,690,100,80,you));
  actors.push_back(new DeathArea(this,start3x+330,840,150,60,you));
  wall3 = new DeathArea(this,start3x+710,30,50,870,you);
  actors.push_back(wall3);
}
void Level9::makeCollectables() {
  //Make the hints
  buildExtra(2300+465,35);
  collect1=collect2=collect3=collect4=0;
  collect4+=buildCoin(35,35,COLLECT_4);
  collect4+=buildCoin(185-15/2.0,190,COLLECT_4);
  collect4+=buildCoin(345,35,COLLECT_4);
  collect4+=buildCoin(210,870,COLLECT_4);
  collect4+=buildCoin(365+15-15/2.0,640,COLLECT_4);
  collect4+=buildCoin(535,870,COLLECT_4);
  collect4+=buildCoin(560-7.5,325-7.5,COLLECT_4);
  collect4+=buildCoin(560-7.5,225-7.5,COLLECT_4);
  collect4+=buildCoin(535,40,COLLECT_4);
  collect4+=buildCoin(600-7.5,325-7.5,COLLECT_4);
  collect4+=buildCoin(600-7.5,225-7.5,COLLECT_4);
  collect4+=buildCoin(610,40,COLLECT_4);
  
  collect1+=buildCoin(880,40,COLLECT_1);
  collect1+=buildCoin(1175,40,COLLECT_1);
  collect1+=buildCoin(930-7.5,320-7.5,COLLECT_1);
  collect1+=buildCoin(1175,110,COLLECT_1);
  collect1+=buildCoin(1090,300-7.5,COLLECT_1);
  
  
  float start2x=1250;
  collect2+=buildCoin(start2x+240-7.5,460,COLLECT_2);
  collect2+=buildCoin(start2x+240-7.5,620,COLLECT_2);
  collect2+=buildCoin(start2x+300-7.5,340,COLLECT_2);
  collect2+=buildCoin(start2x+240-7.5,460,COLLECT_2);
  collect2+=buildCoin(start2x+300-7.5,210,COLLECT_2);
  collect2+=buildCoin(start2x+300-7.5,145,COLLECT_2);
  collect2+=buildCoin(start2x+400+75/2.0-7.5,575,COLLECT_2);
  collect2+=buildCoin(start2x+525+75/2.0-7.5,575,COLLECT_2);
  collect2+=buildCoin(start2x+500-7.5,870,COLLECT_2);
  collect2+=buildCoin(start2x+500-7.5,40,COLLECT_2);
  collect2+=buildCoin(start2x+675+225/2-7.5,680-15-10,COLLECT_2);
  collect2+=buildCoin(start2x+675+225/2-7.5,760,COLLECT_2);
  collect2+=buildCoin(start2x+960,40,COLLECT_2);
  collect2+=buildCoin(start2x+810,40,COLLECT_2);
  collect2+=buildCoin(start2x+825-7.5,325,COLLECT_2);
  collect2+=buildCoin(start2x+825-7.5,420+35-7.5,COLLECT_2);
  collect2+=buildCoin(start2x+825-7.5,570,COLLECT_2);
  collect2+=buildCoin(start2x+510,310+45-7.5,COLLECT_2);
  collect2+=buildCoin(start2x+570+35-7.5,270,COLLECT_2);
  
  collect3+=buildCoin(2300+670,50,COLLECT_3);

  buildHint(80,870,11,"Collect coins to open the path.;");
  buildHint(1250,870,12,"You have entered the antigraity tunnel.; Be careful where you jump.;");
  buildHint(2385,700,13,"Aren't hints annoying?;");
  buildHint(2385,500,14,"Hope you weren't going for the achievement...;");
  buildHint(2385,300,15,"You can turn off all these hints in the option menu.; But you can't get the achievement if they are off.;"); 
buildHint(2500,90,16,"Hah! Got You!;Okay that's the last one.;"); 

}

void Level9::makeSwitches() {
  //Make the save point
  //Wuss save point after first half of first room
  buildSave(755,780,COLLECT_EASY,EASY);
  buildSave(1300,700,WALL_KICK_1,MEDIUM);
  buildSave(2280,780,WALL_KICK_2,MEDIUM);
  buildSave(3300,200,WALL_KICK_3,HARD);
  actors.push_back(new AntiGravity(this,1215,30,300,900,you));
  actors.push_back(new AntiGravity(this,2260,800,20,100,you));
  actors.push_back(new FollowerFactory(this,2300,700,200,50,you,10,&actors));
}
void Level9::makeDetectors() {
  detectors.push_back(new Detector(this,5,5,30,30,&actors2));
  detectors.push_back(new Detector(this,360,5,30,30,&actors2));
  detectors.push_back(new Detector(this,5,225,30,30,&actors2));
  detectors.push_back(new Detector(this,360,225,30,30,&actors2));

  detectors.push_back(new Detector(this,180,610,30,30,&actors2));
  detectors.push_back(new Detector(this,540,600,30,30,&actors2));
  detectors.push_back(new Detector(this,180,890,30,30,&actors2));
  detectors.push_back(new Detector(this,540,880,30,30,&actors2));

  detectors.push_back(new Detector(this,580,10,30,30,&actors2));
  detectors.push_back(new Detector(this,740,20,30,30,&actors2));
  detectors.push_back(new Detector(this,580,880,30,30,&actors2));
  detectors.push_back(new Detector(this,740,890,30,30,&actors2));

  detectors.push_back(new Detector(this,560,860,30,30,&actors2));
  detectors.push_back(new Detector(this,1210,860,30,30,&actors2));

  detectors.push_back(new Detector(this,2260,860,30,30,&actors2));

}

Level* makeLevel9(You* yo, float x, float y, ENT_CODE ent) {
  return new Level9(yo,x,y,ent);
}


void Level9::sendEvent(EVE_CODE eve, Actor* sender) {
  if (eve==COLLECT_1) {
    remove(sender);
    collect1--;
  }
  else if (eve==COLLECT_2) {
    remove(sender);
    collect2--;
  }
  else if (eve==COLLECT_3) {
    remove(sender);
    collect3--;
  }
  else if (eve==COLLECT_4) {
    remove(sender);
    collect4--;
  }
  else
    Level::sendEvent(eve,sender);
  if (collect1<=0)
    wall1->setHeight(800);
  if (collect2<=0)
    wall2->setHeight(800);
  if (collect3<=0)
    wall3->setHeight(800);
  if (collect4<=0&&floor) {
    remove(floor);
    floor = NULL;
  }
    
}

bool Level9::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getX1()>700) {
    next_level=SECRET_1;
    ent_type=WEST;
    return true;
  }
  if (you->getY1()>600) {
    next_level=PUMPKIN;
    ent_type=NORTH;
    return true;
  }
  if (you->getX2()<0) {
    next_level=CLIMB;
    ent_type=EAST;
    return true;
  }
  return Level::isChangeRoom(next_level,ent_type);
}
