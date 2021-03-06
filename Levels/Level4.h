#include "../Level.h"
#include "../Fairy.h"

#ifndef __LEVEL_4_H__
#define __LEVEL_4_H__

#define THROW_EVENT_ERROR 
#define THROW_ENTRANCE_ERROR
class Level4 : public Level {
 public:
  Level4() : Level() {};
  Level4(You* yo, float enterx, float entery, ENT_CODE ent);

  bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);
  void sendEvent(EVE_CODE event,Actor* sender);
 protected:
  void makePlatforms();
  void makeEnemies();
  void makeCollectables();
  void makeSwitches();
  
  Fairy* fairy;
};

Level* makeLevel4(You* yo, float x, float y, ENT_CODE ent);
#endif
