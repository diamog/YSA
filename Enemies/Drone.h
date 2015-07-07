#include "Enemy.h"

#ifndef __DRONE__H__
#define __DRONE__H__

class Drone : public Enemy {
 public:
  Drone();
  Drone(Level* l, float x_,float y_, You* yo,int d);
  
  void act();

  void hitDetector(int adir);
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
 protected:
  int dir;
  float vel;
  float angle;
#ifndef COMPILE_NO_SF
  sf::CircleShape shape;
  sf::CircleShape eye;
#endif
};

#endif
