#include "stdafx.h"

#include "Level.h"
#ifndef COMPILE_NO_VB
#include "Switables/Extra.h"
#else
#include "Extra.h"
#endif
#include "SpeechBubble.h"

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
    
#ifndef COMPILE_NO_SF
    you->messagePause();
    actors.push_back(new SpeechBubble(this,sender->getMessage(),sf::Color(0,255,0)));
#endif
    unsigned int i;
    for (i=0;i<actors.size();i++)
      if (*(actors[i])==*sender) {
	break;
      }
    actors.erase(actors.begin()+i);
    delete sender;
  }
  else if (eve==END_SPEECH) {
    you->messagePause();
		unsigned int i=0;
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
void Level::act() {
  for (unsigned int i =0;i<actors.size();i++)
    if (!you->isPauseM()||!actors[i]->doesPause())
      actors[i]->act();
  for (unsigned int i =0;i<actors2.size();i++)
    if (!you->isPauseM()||!actors[i]->doesPause())
      actors2[i]->act();
  for (unsigned int i=0;i<detectors.size();i++)
    if (!you->isPauseM()||!actors[i]->doesPause())
      detectors[i]->act();
}

#ifndef COMPILE_NO_SF

void Level::windowEvent(sf::Event& event) {
  for (unsigned int i=0;i<actors.size();i++)
    actors[i]->windowEvent(event);
  for (unsigned int i=0;i<actors2.size();i++)
    actors2[i]->windowEvent(event);
  for (unsigned int i=0;i<detectors.size();i++)
    detectors[i]->windowEvent(event);
  
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
#endif
bool Level::hasExtra() {
  return you->hasExtra(me);
}

void Level::buildExtra(float x,float y) {
  if (!hasExtra())
    actors.push_back(new Extra(this,x,y,25,25,you));
}
