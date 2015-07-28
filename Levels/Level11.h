#include "../Level.h"
#include "../Enemies/SmallEye.h"
#include "../Detectors/BigEye.h"
#include "../Platforms/Platform.h"
#include "../Switables/RedSwitch.h"
#include "../Detectors/Block.h"

#ifndef __LEVEL_11_H__
#define __LEVEL_11_H__

#define THROW_EVENT_ERROR 
#define THROW_ENTRANCE_ERROR
class Level11 : public Level {
public:
  Level11() : Level() {};
  Level11(You* yo, float enterx, float entery, ENT_CODE ent);

  bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);
  void sendEvent(EVE_CODE eve, Actor* sender);
  void resetEye();
  void act();
protected:
  void makePlatforms();
  void makeEnemies();
  void makeCollectables();
  void makeSwitches();
  void makeDetectors();
  
  Platform* middle;
  SmallEye* eye;
  BigEye* b1,*b2,*b3;
  RedSwitch* r1,*r2,*r3;
  Block* gblock,*pblock;
  bool isR1,isR2,isR3;
  bool isMove;
};

Level* makeLevel11(You* yo, float x, float y, ENT_CODE ent);
#endif
