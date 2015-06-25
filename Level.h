#ifndef COMPILE_NO_SF
#include <SFML/Graphics.hpp>
#endif
#include <vector>
#include "Actor.h"
#include "Detector.h"
#include "Codes.h"
#include "You.h"
#include <iostream>

#ifndef __LEVEL_H__
#define __LEVEL_H__

class Level {
 public:
  Level();
  Level(You* yo);
  virtual ~Level() {destroy();}

  float getX() {return x;}
  float getY() {return y;}
  virtual void act();

#ifndef COMPILE_NO_SF
  void windowEvent(sf::Event& event); 
  virtual void render(sf::RenderWindow& window);
#endif
  virtual void sendEvent(EVE_CODE eve, Actor* sender);
  void destroy();

  void remove(Actor* actor);
  virtual bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type)=0;
  
  
protected:
  void setup();
  virtual void makePlatforms() {};
  virtual void makeEnemies() {};
  virtual void makeCollectables() {};
  virtual void makeSwitches() {};
  virtual void makeDetectors() {};
  bool hasExtra();
  void buildExtra(float x,float y);
  float x,y;
  std::vector<Actor*> actors;
  std::vector<Actor*> actors2; //to be sent to detectors
  std::vector<Detector*> detectors;
  You* you;
  L_CODE me;
};

#endif
