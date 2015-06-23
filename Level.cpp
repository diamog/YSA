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
  makeDetectors();
}

void Level::destroy() {
  for (unsigned int i=0;i<actors.size();i++) {
    delete actors[i];
  }
  for (unsigned int i=0;i<detectors.size();i++) {
    delete detectors[i];
  }
  detectors.clear();
  actors.clear();
}

void Level::sendEvent(EVE_CODE eve, Actor* sender) {
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
    std::cout<<sender->getMessage()<<std::endl;
    unsigned int i;
    for (i=0;i<actors.size();i++)
      if (*(actors[i])==*sender) {
	break;
      }
    actors.erase(actors.begin()+i);
    delete sender;
  }
  else if (eve == EXTRA) {
    you->getExtra(me);
    unsigned int i;
    for (i=0;i<actors.size();i++)
      if (*(actors[i])==*sender) {
	break;
      }
    actors.erase(actors.begin()+i);
    delete sender;
  }
}
#ifndef COMPILE_NO_SF
void Level::act(sf::Event& event) {
  for (unsigned int i =0;i<actors.size();i++)
    actors[i]->act(event);
  for (unsigned int i =0;i<actors2.size();i++)
    actors2[i]->act(event);
  for (unsigned int i=0;i<detectors.size();i++)
    detectors[i]->act(event);
}

void Level::render(sf::RenderWindow& window) {
  for (unsigned int i=0;i<actors.size();i++)
    actors[i]->render(window);
  for (unsigned int i=0;i<actors2.size();i++)
    actors2[i]->render(window);
  /*
    for (unsigned int i=0;i<detectors.size();i++)
    detectors[i]->render(window);
  */
}
void Level::hasExtra() {
  return you->hasExtra(me);
}
void Level::buildExtra(float x,float y) {
  if (!hasExtra())
    actors.push_back(new Extra(this,x,y,25,25,you);
}
#endif
