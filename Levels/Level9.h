#include "../Level.h"
#include "../Platforms/KickPlat.h"
#include "../Enemies/DeathArea.h"
#ifndef __LEVEL_9_H__
#define __LEVEL_9_H__

#define THROW_EVENT_ERROR 
#define THROW_ENTRANCE_ERROR
class Level9 : public Level {
 public:
  Level9() : Level() {};
  Level9(You* yo, float enterx, float entery, ENT_CODE ent);
  void sendEvent(EVE_CODE eve, Actor* sender);
  bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);
 protected:
  void makePlatforms();
  void makeEnemies();
  void makeCollectables();
  void makeSwitches();
  void makeDetectors();
  Platform* floor;
  KickPlat* wall1;
  KickPlat* wall2;
  DeathArea* wall3;
  
  int collect1,collect2,collect3,collect4;
};

Level* makeLevel9(You* yo, float x, float y, ENT_CODE ent);
#endif
