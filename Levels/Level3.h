#include "../Level.h"

#ifndef __LEVEL_3_H__
#define __LEVEL_3_H__

#define THROW_EVENT_ERROR 
#define THROW_ENTRANCE_ERROR
class Level3 : public Level {
 public:
  Level3() : Level() {};
  Level3(You* yo, float enterx, float entery, ENT_CODE ent);

	bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);
 protected:
  void makePlatforms();
  void makeEnemies();
  void makeCollectables();
  void makeSwitches();
	void makeDetectors();
  

};

Level* makeLevel3(You* yo, float x, float y, ENT_CODE ent);
#endif
