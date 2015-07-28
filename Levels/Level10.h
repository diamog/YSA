#include "../Level.h"
#include "../Fairy.h"

#ifndef __LEVEL_10_H__
#define __LEVEL_10_H__

#define THROW_EVENT_ERROR 
#define THROW_ENTRANCE_ERROR
class Level10 : public Level {
public:
  Level10() : Level() {};
  Level10(You* yo, float enterx, float entery, ENT_CODE ent);

  bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);

  void act();

protected:
  void makeEnemies();
  void makeCollectables();  
};

Level* makeLevel10(You* yo, float x, float y, ENT_CODE ent);
#endif
