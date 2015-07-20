#include "../Level.h"
#include "../Enemies/PumpkinHead.h"
#include "../Enemies/Pumpkin.h"
#ifndef __BOSS_2_H__
#define __BOSS_2_H__

#define THROW_EVENT_ERROR 
#define THROW_ENTRANCE_ERROR
class Boss2 : public Level {
 public:
  Boss2() : Level() {};
  Boss2(You* yo, float enterx, float entery, ENT_CODE ent);

  bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);
  template <class Plat,class TPlat> void makeP();
  void act();

  void sendEvent(EVE_CODE eve, Actor* sender);
 protected:
  void makePlatforms();
  void makeEnemies();
  void makeCollectables();
  int part;
  PumpkinHead* headL;
  PumpkinHead* headR;
  Platform* plat1;
  Pumpkin* pumpkin;
};

Level* makeBoss2(You* yo, float x, float y, ENT_CODE ent);
#endif
