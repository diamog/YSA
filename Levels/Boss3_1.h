#include "../Level.h"

#ifndef __BOSS_3_1_H__
#define __BOSS_3_1_H__

#include "../Enemies/CloudBoss.h"
#include "../Enemies/SmallEye.h"
#include "../Detectors/BigEye.h"
#include "../Platforms/Platform.h"
#define THROW_EVENT_ERROR 
#define THROW_ENTRANCE_ERROR
class Boss3_1 : public Level {
 public:
  Boss3_1() : Level() {};
  Boss3_1(You* yo, float enterx, float entery, ENT_CODE ent);

  bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);
  void act();

  void sendEvent(EVE_CODE eve, Actor* sender);

 protected:
  void makePlatforms();
  void makeEnemies();
  void makeCollectables();
  void makeSwitches();
  void makeDetectors();
  int dir;

  Extra* extra;
  Platform* left;
  CloudBoss1* boss;
  SmallEye* eye;
  BigEye* b1;
  BigEye* b2;
};

Level* makeBoss3_1(You* yo, float x, float y, ENT_CODE ent);
#endif
