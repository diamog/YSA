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
  virtual ~Level() {destroy();}

  float getX() {return x;}
  float getY() {return y;}

#ifndef COMPILE_NO_SF
  virtual void act(sf::Event& event);
  virtual void render(sf::RenderWindow& window);
#endif
  virtual void event(EVE_CODE eve, Actor* sender)=0;
  void destroy();
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
