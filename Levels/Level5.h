#include "../Level.h"
#include "../Enemies/DeathArea.h"

#ifndef __LEVEL_5_H__
#define __LEVEL_5_H__

#define THROW_EVENT_ERROR 
#define THROW_ENTRANCE_ERROR
class Level5 : public Level {
 public:
  Level5() : Level() {};
  Level5(You* yo, float enterx, float entery, ENT_CODE ent);

  void act();
  void sendEvent(EVE_CODE eve, Actor* sender);
  bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);
 protected:
  void makePlatforms();
  void makeEnemies();
  void makeCollectables();
  void makeSwitches();
  DeathArea* right_wall;

};

Level* makeLevel5(You* yo, float x, float y, ENT_CODE ent);
#endif
