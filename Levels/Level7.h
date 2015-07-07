#include "../Level.h"

#ifndef __LEVEL_7_H__
#define __LEVEL_7_H__

#define THROW_EVENT_ERROR 
#define THROW_ENTRANCE_ERROR
class Level7 : public Level {
 public:
  Level7() : Level() {};
  Level7(You* yo, float enterx, float entery, ENT_CODE ent);

  bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);
 protected:
  void makePlatforms();
  void makeEnemies();
  void makeCollectables();
  void makeSwitches();
  void makeDetectors();
};

Level* makeLevel7(You* yo, float x, float y, ENT_CODE ent);
#endif
