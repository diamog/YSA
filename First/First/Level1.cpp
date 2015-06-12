#incldue "Level1.h"

Level1::Level1(You* yo, float enterx, float entery, ENT_CODE ent) : Level1(yo) {
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
    THROW_ENTRANCE_ERROR
}

void Level1::event(EVE_CODE eve) {
  if (eve==SPEECH_1) {
    //Tutorial on moving
  }
  else if (eve==SPEECH_2) {
    //Tutorial on jumping
  }
  else if (eve==SAVE_1) {
    //Save savepoint 0
  }
  else 
    THROW_EVENT_ERROR
    
}

void Level1::makePlatforms() {
  actors.push_back(new Platform(0,height-30,width,30,&you));
  actors.push_back(new Platform(0,0,30,height-30,&you));
  actors.push_back(new Platform(width-30,0,30,height-30,&you));
  actors.push_back(new Platform(width-130,height-100,100,25,&you));

}

void Level1::makeCollectables() {
  //Make the hints
}

void Level1::makeSwitches() {
  //Make the save point 
}