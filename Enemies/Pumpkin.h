#include "Enemy.h"
#include "PBullet.h"
#include "PGhost.h"

#ifndef __PUMPKIN__H__
#define __PUMPKIN__H__

class Pumpkin : public Enemy {
 public:
  Pumpkin();
  Pumpkin(Level* l, You* yo);
  ~Pumpkin();
  void attack1(); 
  void attack2();
  void attack3();
  void attack4();
  void attack5();
  void act();
  void turnOn() {part=1;}
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
 protected:
  int part;
  int delay;
  unsigned int ticks;
#ifndef COMPILE_NO_SF
  sf::CircleShape shape;
#endif
  float shotx,shoty;
  PGhost* ghostL;
  PGhost* ghostR;
  std::vector<PBullet*> bullets;
};

#endif
