#include "Enemy.h"
#include "CBullet.h"
#include "SmallEye.h"
#ifndef __CLOUD__H__
#define __CLOUD__H__

class Cloud : public Enemy {
 public:
  Cloud();
  Cloud(Level* l, float x_,float y_, You* yo,SmallEye* e,
	std::vector<CBullet*>* b);
  
  void act();
  bool getDead() const {return isDead;}
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
  void speedup() {rate++;}
 protected:
  int ticks;
  int max_tick;
  int rate;
  std::vector<CBullet*>* bullets;
#ifndef COMPILE_NO_SF
  sf::CircleShape shape;
#endif
  bool isDead;
  SmallEye* eye;
};

#endif
