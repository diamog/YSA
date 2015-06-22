#include "../Level.h"

#ifndef __BOSS_1_H__
#define __BOSS_1_H__

#include "../Enemies/ColorBoss.h"
#define THROW_EVENT_ERROR 
#define THROW_ENTRANCE_ERROR
class Boss1 : public Level {
 public:
  Boss1() : Level() {};
  Boss1(You* yo, float enterx, float entery, ENT_CODE ent);

  bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);

#ifndef COMPILE_NO_SF
  void act(sf::Event& event);
#endif

  void sendEvent(EVE_CODE eve, Actor* sender);
 protected:
  void makePlatforms();
  void makeEnemies();
  void makeCollectables();
  ColorBoss* boss;

};

Level* makeBoss1(You* yo, float x, float y, ENT_CODE ent);
#endif
