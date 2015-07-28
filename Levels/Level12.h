#include "../Level.h"
#include "../Enemies/SmallEye.h"
#include "../Detectors/BigEye.h"
#include "../Platforms/Platform.h"
#include "../Switables/RedSwitch.h"
#include "../Detectors/Block.h"

#ifndef __LEVEL_12_H__
#define __LEVEL_12_H__

#define THROW_EVENT_ERROR 
#define THROW_ENTRANCE_ERROR
class Level12 : public Level {
public:
  Level12() : Level() {};
  Level12(You* yo, float enterx, float entery, ENT_CODE ent);

  bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);
  void sendEvent(EVE_CODE eve, Actor* sender);
  void act();

protected:
  void makePlatforms();
  void makeEnemies();
  void makeCollectables();
  void makeSwitches();
  void makeDetectors();
  
  Platform* middle;
  SmallEye* eye;
  BigEye* b1;
  bool isMove;
};

Level* makeLevel12(You* yo, float x, float y, ENT_CODE ent);
#endif
