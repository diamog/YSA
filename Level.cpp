#include "stdafx.h"

#include "Level.h"
#ifndef COMPILE_NO_VB
#include "Switables/Extra.h"
#include "Switables/Hint.h"
#include "Switables/Coin.h"
#else
#include "Extra.h"
#include "Hint.h"
#include "Coin.h"
#endif
#include "SpeechBubble.h"
#include "Extras/utilities.h"
#include "Graphics/SaveGraphic.h"
#include "Switables/Save.h"
Level::Level() {
  you = NULL;
  x=y=0;
  isWarp=false;
}

Level::Level(You* yo) {
  you = yo;
  x=y=0;
  width=700;
  height=600;
  isboss=false;
  canMove=true;
  isWarp=false;
  save_sfx = getSong("Save");
}

void Level::setup() {
  makeCollectables();
  makeSwitches();
  makePlatforms();
  makeEnemies();
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
  if (actor==NULL)
    return;
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
    if (you->boss1()&&you->getSave()==GAME_START)
      buildAchievement(NO_SAVE);
    you->save(s);
    buildAchievement(SAVE_1);
    actors.push_back(new SaveGraphic(this,you->boss1()));		
    // Play the music
    save_sfx->play();
  }
  else if (eve == SPEECH) {
    you->getHint(sender->getVal());
#ifndef COMPILE_NO_SF
    you->messagePause();
    actors.push_back(new SpeechBubble(this,sender->getMessage(),sf::Color(0,255,0),you->getY1(),END_HINT));
#endif
    remove(sender);
  }
  else if (eve==END_HINT) {
    you->messagePause();
    remove(sender);
  }
  else if (eve==END_SPEECH) {
    you->controlPause();
    remove(sender);
  }
  else if (eve == EXTRA) {
    you->getExtra(me);
    remove(sender);
  }
  else if (eve==KILL) {
    remove(sender);
  }
  else if (eve==NOTHING) {}
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
  if (canMove) {
    float cx,cy;
    getObjectCenter(you,cx,cy);
    if (cx>700*2/3) {
      if (x+700<width) {
	float dx = cx - 700*2/3;
	dx = std::min(dx,width-700-y);
	dx = std::min(dx,5.0f);
	x+=dx;
	you->shiftX(-dx);
      }
      else 
	x = width-700;
    }
    else if (cx<700*1/3) {
      if (x>0) {
	float dx = cx - 700*1/3;
	dx = std::max(dx,-5.0f);
	x+=dx;
	you->shiftX(-dx);
      }
      else
	x=0;
    }
    if (cy>600*2/3) {
      if (y+600<height) {
      
	float dy = cy - 600*2/3;
	dy = std::min(dy,height-600-y);
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
  for (unsigned int i=0;i<detectors.size();i++)
    detectors[i]->render(window);
  for (unsigned int i=0;i<actors.size();i++)
    actors[i]->render(window);
  for (unsigned int i=0;i<actors2.size();i++)
    actors2[i]->render(window);
}
#endif

bool Level::isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type) {
  if (isWarp) {
    next_level=SPLIT;
    ent_type=PORTAL_1;
    return true;
  }
  return false;
}

void Level::centerLevel() {
  float cx,cy;
  getObjectCenter(you,cx,cy);
  float newx,newy;
  if(cx>700)
    newx=cx-350;

  if (newx>width-700)
    newx=width-700;
  you->shiftX(x-newx);
  x=newx;
  if(cy>600)
    newy=cy-300;
  if (newy>height-600)
    newy=height-600;
  you->shiftY(y-newy);
  y=newy;
}
Extra* Level::buildExtra(float x,float y) {
  if (!you->hasExtra(me)) {
    Extra* temp = new Extra(this,x,y,25,25,you); 
    actors.push_back(temp);
    return temp;
  }
  return NULL;
}
void Level::buildHint(float x,float y,int code,std::string m) {
  if (!you->hasHint(code))
    actors.push_back(new Hint(this,x,y,30,you,m,code));
}

int Level::buildCoin(float x,float y,EVE_CODE eve) {
  actors.push_back(new Coin(this,x,y,you,eve));
  return 1;
}

void Level::buildSave(float x, float y, SAVE_CODE s,DIFF_CODE d) {
  if (you->getDifficulty()<=d) {
    actors.push_back(new Save(this,x,y,40,you,s));
  }
}
