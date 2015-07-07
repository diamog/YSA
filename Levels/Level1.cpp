#include "stdafx.h"
#include "Level1.h"
#include "../Platforms/Platform.h"
#include "../Platforms/ThinPlat.h"
#include "../Switables/Hint.h"
#include "../Switables/Save.h"
#include "../SpeechBubble.h"
#include <iostream>

Level1::Level1(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
  me = START;
  setup();
  fairy = new Fairy(this,-30,300);
  actors.push_back(fairy);
  if (ent == MISC_1) {
    //Enter through beginning of game
    you->setPosition(enterx,entery);
#ifndef COMPILE_NO_SF
    you->messagePause();
    actors.push_back(new SpeechBubble(this,"What? Where am I? Why is the world so bland?; AND WHY AM I A YELLOW SQUARE?!;",sf::Color(255,255,0),you->getY1(),MISCE_1));
#endif
  }
  else if (ent== NORTH) {
    //Fall from Level 2
    you->setPosition(you->getX1(),2,true);
  }
  else if (ent== LOAD_1) {
    //Load into savepoint 0
    you->setPosition(140,240);
  }  
  else
    THROW_ENTRANCE_ERROR;
}


void Level1::makePlatforms() {
  actors.push_back(new Platform(this,0,570,700,30,you));
  actors.push_back(new Platform(this,0,-30,30,600,you));
  actors.push_back(new Platform(this,670,-30,30,600,you));
  actors.push_back(new Platform(this,570,500,100,25,you));
  actors.push_back(new Platform(this,470,380,100,25,you));
  actors.push_back(new Platform(this,130,300,100,25,you));
  actors.push_back(new Platform(this,300,100,150,25,you));
  
}

void Level1::makeCollectables() {
  //Make the hints
  buildHint(340,535,0,"Use the left and right arrow keys to move.;");
  buildHint(585,465,1,"Use the up arrow key to jump.;");
  buildHint(540,345,2,"In mid air use the up arrow key to jump again.;");
  buildHint(250,150,3,"The sooner you double jump the higher you will go.;");
  buildExtra(635,10);
}

void Level1::makeSwitches() {
  //Make the save point 
  actors.push_back(new Save(this, 130,230,40,you,ROOM_1));
}


Level* makeLevel1(You* yo, float x, float y, ENT_CODE ent) {
  return new Level1(yo,x,y,ent);
}

void Level1::sendEvent(EVE_CODE eve, Actor* sender) {
  if (eve ==MISCE_1) {
    remove(sender);
    fairy->turnOn(1);
  }
  else if (eve==MISCE_2) {
    remove(sender);
#ifndef COMPILE_NO_SF
    actors.push_back(new SpeechBubble(this,"Woah... What was that?; I guess I should follow it and ask it what is going on.;",sf::Color(255,255,0),you->getY1()));
#endif
  }
  else
    Level::sendEvent(eve,sender);
}
bool Level1::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (you->getY2()<0) {
    next_level=DIE;
    ent_type=SOUTH;
    return true;
  }
  return false;
}
