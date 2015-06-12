#include "Level.h"

class Level1 : public Level {
 public:
  Level1();
  Level1(You* yo, float enterx, float entery, ENT_CODE ent);
 protected:
  void makePlatforms();
  void makeEnemies();
  void makeCollectables();
  void makeSwitches();
  

}
