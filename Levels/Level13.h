#include "../Level.h"
#include "../Enemies/SmallEye.h"
#include "../Detectors/BigEye.h"
#include "../Platforms/Platform.h"
#include "../Switables/RedSwitch.h"
#include "../Detectors/Block.h"
#include "../Detectors/Wall.h"

#ifndef __LEVEL_13_H__
#define __LEVEL_13_H__

#define THROW_EVENT_ERROR 
#define THROW_ENTRANCE_ERROR
class Level13 : public Level {
public:
  Level13() : Level() {};
  Level13(You* yo, float enterx, float entery, ENT_CODE ent);

  bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);
  void sendEvent(EVE_CODE eve, Actor* sender);
  void act();

protected:
  void makePlatforms();
  void makeEnemies();
  void makeCollectables();
  void makeSwitches();
  void makeDetectors();
  
  Platform* ceiling;
  SmallEye* eye;
  BigEye* b1,*b2;
  Block *pblock1,*pblock2,*pblock3;
  Block *gblock1,*gblock2,*gblock3;
  Wall  *owall1, *owall2, *owall3;
  bool isMove;
};

Level* makeLevel13(You* yo, float x, float y, ENT_CODE ent);
#endif
