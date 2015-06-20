#include "stdafx.h"

#include "Level.h"

Level::Level() {
  you = NULL;
  x=y=0;
}

Level::Level(You* yo) {
  you = yo;
  x=y=0;
  
}

void Level::setup() {
  makePlatforms();
  makeEnemies();
  makeCollectables();
  makeSwitches();
}

void Level::destroy() {
  for (unsigned int i=0;i<actors.size();i++)
    delete actors[i];
}

void Level::event(EVE_CODE eve, Actor* sender) {
  if (eve == SAVE) {
    S_CODE s = sender->getSave();
    you->save(s);
  }
  else if (eve == SPEECH) {
    //Tutorial on moving or jumping
    /*
    all.off();
    actors.push_back(new SpeechBubble(sender->getMessage(),GREEN));
    */
    unsigned int i;
    for (i=0;i<actors.size();i++)
      if (*(actors[i])==*sender)
	    break;
    actors.erase(actors.begin()+i);
    delete sender;
  }
}
#ifndef COMPILE_NO_SF
void Level::act(sf::Event& event) {
  for (unsigned int i =0;i<actors.size();i++)
    actors[i]->act(event);
}

void Level::render(sf::RenderWindow& window) {
  for (unsigned int i=0;i<actors.size();i++)
    actors[i]->render(window);
}
#endif