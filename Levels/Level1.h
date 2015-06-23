#include "../Level.h"

#ifndef __LEVEL_1_H__
#define __LEVEL_1_H__

#define THROW_EVENT_ERROR 
#define THROW_ENTRANCE_ERROR
class Level1 : public Level {
 public:
  Level1() : Level() {};
  Level1(You* yo, float enterx, float entery, ENT_CODE ent);

  bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);
 protected:
  void makePlatforms();
  // void makeEnemies();
  void makeCollectables();
  void makeSwitches();
  

};

Level* makeLevel1(You* yo, float x, float y, ENT_CODE ent);
#endif
