#include "../Level.h"
#include "../Fairy.h"

#include "../Platforms/Platform.h"

#ifndef __LEVEL_16_H__
#define __LEVEL_16_H__

#define THROW_EVENT_ERROR 
#define THROW_ENTRANCE_ERROR
class Level16 : public Level {
 public:
  Level16() : Level() {};
  Level16(You* yo, float enterx, float entery, ENT_CODE ent);

  bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);

 protected:
  void makePlatforms();

  void makeCollectables();
  void makeSwitches();
};

Level* makeLevel16(You* yo, float x, float y, ENT_CODE ent);
#endif
