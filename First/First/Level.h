#include <SFML/Graphics.hpp>
#include <vector>
#include "Actor.h"
#include "Codes.h"

#ifndef __LEVEL_H__
#define __LEVEL_H__

class Level {
 public:
  Level();
  Level(You* yo, float enterx, float entery, ENT_CODE ent);
  virtual ~Level();

  float getX() {return x;}
  float getY() {return y;}

  virtual void act();
  virtual void render(sf::RenderWindow& window);

  virtual void event(EVE_CODE eve, Actor* sender)=0;

 protected:
  virtual void makePlatforms() = 0;
  virtual void makeEnemies() = 0;
  virtual void makeCollectables() = 0;
  virtual void makeSwitches() = 0;
  
  float x,y;
  std::vector<Actor*> actors;
  You* you;

};

#endif
