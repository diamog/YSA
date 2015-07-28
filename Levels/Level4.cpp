#include "stdafx.h"
#include "Level4.h"
#include "../Platforms/Platform.h"
#include "../Platforms/ThinPlat.h"
#include "../Switables/Hint.h"
#include "../Switables/Save.h"
#include "../Enemies/DeathArea.h"
#include "../SpeechBubble.h"
#include <iostream>

Level4::Level4(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  me = SPLIT;
  setup();
  fairy = new Fairy(this,500,100);
  actors.push_back(fairy);
  if (ent== SOUTH) {
    you->setPosition(enterx,598,true);
  }
  else if (ent== LOAD_1) {
    //Load into savepoint 1
    you->setPosition(610,120);
  } 
  else if(ent==EAST) {
    you->setPosition(698,entery,true);
  }
  else if (ent==NORTH) {
    you->setPosition(enterx,-18,true);
  }
  else if (ent==MISC_1) {
    fairy->turnOn(3);
    you->setPosition(enterx,-18,true);
    you->controlPause();
    actors.push_back(new SpeechBubble(this,"Hurrah! You have returned the color to this land and saved me too!; I am one of the 5 protector fairies of this land.; You must be destined to save this entire world or something...;",sf::Color(200,0,200),you->getY1(),MISCE_1)); 
    you->enterSplit();
  }
  else if (ent==PORTAL_1) {
    you->setPosition(200,20);
    you->setFall();
  }
  else
    throw THROW_ENTRANCE_ERROR;
}


void Level4::makePlatforms() {
  actors.push_back(new Platform(this,0,-30,30,630,you));
  actors.push_back(new Platform(this,670,-30,30,430,you));
  actors.push_back(new Platform(this,30,80,400,40,you));
  actors.push_back(new Platform(this,170,250,500,50,you));
  actors.push_back(new Platform(this,275,380,150,30,you));
  actors.push_back(new Platform(this,30,500,225,30,you));
  actors.push_back(new Platform(this,450,500,150,30,you));
  actors.push_back(new Platform(this,600,530,100,30,you));
  
}
void Level4::makeEnemies() {
  actors.push_back(new DeathArea(this,380,120,50,50,you));
  actors.push_back(new DeathArea(this,170,200,60,50,you));
  actors.push_back(new DeathArea(this,30,120,60,70,you));
  actors.push_back(new DeathArea(this,120,250,50,80,you));
  actors.push_back(new DeathArea(this,30,380,80,60,you));
  actors.push_back(new DeathArea(this,375,340,50,40,you));
  actors.push_back(new DeathArea(this,490,300,30,80,you));
  actors.push_back(new DeathArea(this,570,400,100,30,you));
  actors.push_back(new DeathArea(this,255,530,30,70,you));
  actors.push_back(new DeathArea(this,425,410,30,190,you));

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
  return Level::isChangeRoom(next_level,ent_type);
}

void Level4::sendEvent(EVE_CODE event,Actor* sender) {
  if (event==MISCE_1) {
    remove(sender);
    actors.push_back(new SpeechBubble(this,"Is there some kind of prophecy dictating that a yellow square will save the world?;",sf::Color(255,255,0),you->getY1(),MISCE_2)); 
    
  }
  else if (event==MISCE_2) {
    remove(sender);
    actors.push_back(new SpeechBubble(this,"NOPE!; But I beg you. Please find my fellow fairies.; Together we can stop the deterioration of the world.; I will remain here awaiting your return; To the right I sense a profound darkness that has yet to take form.; Below us is a long pit. I will slow your descent so that you can safely make it down.;",sf::Color(200,0,200),you->getY1())); 
  }
  else 
    Level::sendEvent(event,sender);
  
}
