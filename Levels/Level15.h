#include "../Level.h"
#include "../Fairy.h"

#include "../Platforms/Platform.h"

#ifndef __LEVEL_15_H__
#define __LEVEL_15_H__

#define THROW_EVENT_ERROR 
#define THROW_ENTRANCE_ERROR
class Level15 : public Level {
 public:
  Level15() : Level() {};
  Level15(You* yo, float enterx, float entery, ENT_CODE ent);

  void act();

  bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);
  void sendEvent(EVE_CODE event,Actor* sender);
 protected:
  void makePlatforms();
  void makeEnemies();
  void makeCollectables();
  void makeSwitches();
  bool isPortal;
  Platform* elevator;
};

Level* makeLevel15(You* yo, float x, float y, ENT_CODE ent);
#endif
