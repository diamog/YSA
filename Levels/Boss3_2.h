#include "../Level.h"

#ifndef __BOSS_3_2_H__
#define __BOSS_3_2_H__

#include "../Enemies/CloudBoss.h"
#include "../Enemies/SmallEye.h"
#include "../Detectors/BigEye.h"
#include "../Platforms/Platform.h"
#define THROW_EVENT_ERROR 
#define THROW_ENTRANCE_ERROR
class Boss3_2 : public Level {
 public:
  Boss3_2() : Level() {};
  Boss3_2(You* yo, float enterx, float entery, ENT_CODE ent);

  bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);
  void act();

  void sendEvent(EVE_CODE eve, Actor* sender);

 protected:
  void makePlatforms();
  void makeEnemies();
  void makeCollectables();
  void makeSwitches();
  void makeDetectors();
  bool isMove;
  bool movePlat;
  Platform* right,*top;
  CloudBoss2* boss;
  SmallEye* eye;
  BigEye* b1;
  BigEye* b2;
};

Level* makeBoss3_2(You* yo, float x, float y, ENT_CODE ent);
#endif
