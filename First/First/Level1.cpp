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
    
}

void Level1::makePlatforms() {
  int width = 700;int height = 600;
  actors.push_back(new Platform(this,0,height-30.0f,width+0.0f,30,you));
  actors.push_back(new Platform(this,0,0,30,height-30.0f,you));
  actors.push_back(new Platform(this,width-30.0f,0,30,height-30.0f,you));
  actors.push_back(new Platform(this,width-130.0f,height-100.0f,100,25,you));
}

void Level1::makeCollectables() {
  //Make the hints
  actors.push_back(new Hint(this,0,0,0,0,you,"Something about moving"));
  actors.push_back(new Hint(this,0,0,0,0,you,"Something about jumping"));
  actors.push_back(new Hint(this,0,0,0,0,you,"Something about double jumping"));
  actors.push_back(new Hint(this,0,0,0,0,you,
			    "Something about double jumping higher"));

}

void Level1::makeSwitches() {
  //Make the save point 
  actors.push_back(new Save(this, 0,0,0,0,you));
}


Level* makeLevel1(You* yo, float x, float y, ENT_CODE ent) {
  return new Level1(yo,x,y,ent);
}
