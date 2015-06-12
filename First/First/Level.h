#include <vector>
#include "Actor.h"
#include "Codes.h"

class Level {
 public:
  Level();
  Level(You* yo, float enterx, float entery, ENT_CODE ent);

  float getX() {return x;}
  float getY() {return y;}

  void act();
  void render();

  virtual void event(EVE_CODE eve)=0;
 protected:
  virtual void makePlatforms() = 0;
  virtual void makeEnemies() = 0;
  virtual void makeCollectables() = 0;
  virtual void makeSwitches() = 0;
  
  float x,y;
  std::vector<Actor*> actors;
  You* you;

};
