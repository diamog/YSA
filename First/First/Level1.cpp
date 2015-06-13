#include "stdafx.h"
#include "Level1.h"
#include "Platform.h"
#include <iostream>

Level1::Level1(You* yo, float enterx, float entery, ENT_CODE ent) : Level(yo) {
	setup();
  if (ent == MISC_1) {
    //Enter through beginning of game
  }
  else if (ent== NORTH) {
    //Fall from Level 2
  }
  else if (ent== LOAD_1) {
    //Load into savepoint 0
  }  
  else
    THROW_ENTRANCE_ERROR;
}

void Level1::event(EVE_CODE eve, Actor* sender) {
  if (eve==SPEECH) {
    //Tutorial on moving or jumping
    /*
    all.off();
    actors.push_back(new SpeechBubble(sender->getMessage(),GREEN));
    */
    unsigned int i;
    for (i=0;i<actors.size();i++)
      //if (*(actors[i])==*sender)
	    break;
    actors.erase(actors.begin()+i);
    delete sender;
  }
  else if (eve==SAVE_1) {
    //Save savepoint 0
  }
  else 
    THROW_EVENT_ERROR;
    
}

void Level1::makePlatforms() {
  int width = 700;int height = 600;
  actors.push_back(new Platform(0,height-30.0f,width+0.0f,30,you));
  actors.push_back(new Platform(0,0,30,height-30.0f,you));
  actors.push_back(new Platform(width-30.0f,0,30,height-30.0f,you));
  actors.push_back(new Platform(width-130.0f,height-100.0f,100,25,you));
	std::cout<<"hi";
}

void Level1::makeCollectables() {
  //Make the hints
}

void Level1::makeSwitches() {
  //Make the save point 
}
