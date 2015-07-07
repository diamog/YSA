#include "stdafx.h"

#include "Level.h"
#ifndef COMPILE_NO_VB
#include "Switables/Extra.h"
#include "Switables/Hint.h"
#else
#include "Extra.h"
#include "Hint.h"
#endif
#include "SpeechBubble.h"
#include "Extras/utilities.h"
#include "Graphics/SaveGraphic.h"
Level::Level() {
  you = NULL;
  x=y=0;
}

Level::Level(You* yo) {
  you = yo;
  x=y=0;
  width=700;
  height=600;
  isboss=false;
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

void Level::remove(Actor* actor) {
  unsigned int i;
  for (i=0;i<actors.size();i++) 
    if (*(actors[i])==*actor)
      break;
  actors.erase(actors.begin()+i);
  delete actor;
}
  
void Level::sendEvent(EVE_CODE eve, Actor* sender) {
  if (eve == SAVE) {
    S_CODE s = sender->getSave();
    you->save(s);
    actors.push_back(new SaveGraphic(this));
  }
  else if (eve == SPEECH) {
    you->getHint(sender->getVal());
#ifndef COMPILE_NO_SF
    you->messagePause();
    actors.push_back(new SpeechBubble(this,sender->getMessage(),sf::Color(0,255,0),you->getY1()));
#endif
    remove(sender);
  }
  else if (eve==END_SPEECH) {
    you->messagePause();
    remove(sender);
  }
  else if (eve == EXTRA) {
    you->getExtra(me);
    remove(sender);
  }
  else if (eve== FACTORY) {}
  else if (eve==KILL) {
    remove(sender);
  }
  else {
    throw 1;
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
  float cx,cy;
  getObjectCenter(you,cx,cy);
  if (cx>700*2/3&&x+700<width) {
    if (x+700<width) {
      float dx = cx - 700*2/3;
      x+=dx;
      you->shiftX(-dx);
    }
    else 
      x = width-700;
  }
  else if (cx<700*1/3) {
    if (x>0) {
      float dx = cx - 700*1/3;
      x+=dx;
      you->shiftX(-dx);
    }
    else
      x=0;
  }
  if (cy>600*2/3&&y+600<height) {
    if (y+600<height) {
      
      float dy = cy - 600*2/3;
      y+=dy;
      you->shiftY(-dy);
      
    }
    else 
      y = height-600;
  }
  else if (cy<600*1/3) {
    if (y>0) {
      float dy = cy - 600*1/3;
      y+=dy;
      you->shiftY(-dy);
    }
    else
      y=0;
  }
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
#ifdef COMPILE_DEBUG
  for (unsigned int i=0;i<detectors.size();i++)
    detectors[i]->render(window);
#endif

}
#endif

void Level::buildExtra(float x,float y) {
  if (!you->hasExtra(me))
    actors.push_back(new Extra(this,x,y,25,25,you));
}
void Level::buildHint(float x,float y,int code,std::string m) {
  if (!you->hasHint(code))
    actors.push_back(new Hint(this,x,y,30,you,m,code));
}
