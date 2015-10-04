#include "../Level.h"
#include "../Fairy.h"
#include "../Enemies/CatBoss.h"
#include "../Platforms/Platform.h"

#ifndef __BOSS_CAT_H__
#define __BOSS_CAT_H__

#define THROW_EVENT_ERROR 
#define THROW_ENTRANCE_ERROR
class BossCat : public Level {
 public:
  BossCat() : Level() {};
  BossCat(You* yo, float enterx, float entery, ENT_CODE ent);

  void act();

  bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);
  void sendEvent(EVE_CODE event,Actor* sender);
 protected:
  void makePlatforms();
  void makeEnemies();
  void makeCollectables();
  bool isPortal;
  CatBoss* boss;
};

Level* makeBossCat(You* yo, float x, float y, ENT_CODE ent);
#endif
