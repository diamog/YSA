#ifndef COMPILE_NO_SF
#include <SFML/Graphics.hpp>
#endif
#include <vector>
#include "Actor.h"
#include "Codes.h"
#include "You.h"
#include <iostream>

#ifndef __LEVEL_H__
#define __LEVEL_H__

class Level {
 public:
  Level();
  Level(You* yo);
  virtual ~Level();

  float getX() {return x;}
  float getY() {return y;}

  virtual void act();
#ifndef COMPILE_NO_SF
  virtual void render(sf::RenderWindow& window);
#endif
  virtual void event(EVE_CODE eve, Actor* sender)=0;

 protected:
  void setup();
  virtual void makePlatforms() {std::cout<<"meow";};
  virtual void makeEnemies() {};
  virtual void makeCollectables() {};
  virtual void makeSwitches() {};
  
  float x,y;
  std::vector<Actor*> actors;
  You* you;

};

#endif
