#include "../Level.h"
#include "../Platforms/InviPlat.h"

#ifndef __SECRET_1_H__
#define __SECRET_1_H__

#define THROW_EVENT_ERROR 
#define THROW_ENTRANCE_ERROR
class Secret1 : public Level {
public:
  Secret1() : Level() {};
  Secret1(You* yo, float enterx, float entery, ENT_CODE ent);

  bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);
  void sendEvent(EVE_CODE eve, Actor* sender);

protected:
  void makePlatforms();
  void makeEnemies();
  void makeCollectables();
  void makeSwitches();
  void makeDetectors();
  
  int collect1;
  InviPlat* block;
  bool isPortal;
  bool gotFairy;
};

Level* makeSecret1(You* yo, float x, float y, ENT_CODE ent);
#endif
