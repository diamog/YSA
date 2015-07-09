#include "../Level.h"

#ifndef __LEVEL_8_H__
#define __LEVEL_8_H__

#define THROW_EVENT_ERROR 
#define THROW_ENTRANCE_ERROR
class Level8 : public Level {
 public:
  Level8() : Level() {};
  Level8(You* yo, float enterx, float entery, ENT_CODE ent);
  void sendEvent(EVE_CODE eve, Actor* sender);
  bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);
 protected:
  void makePlatforms();
  void makeEnemies();
  void makeCollectables();
  void makeSwitches();
  void makeDetectors();
};

Level* makeLevel8(You* yo, float x, float y, ENT_CODE ent);
#endif
