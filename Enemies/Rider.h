#include "Enemy.h"

#ifndef __RIDER__H__
#define __RIDER__H__

class Rider : public Enemy {
 public:
  Rider();
  Rider(Level* l, float x_,float y_, You* yo,int d);
  
  void act();

  void hitDetector(int adir);
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
 protected:
  int dir;
  float vel;
  float x1;
  float x2;
  float y1;
  float y2;
#ifndef COMPILE_NO_SF
  sf::RectangleShape top;
  sf::CircleShape rightSide;
  sf::RectangleShape base;
  sf::CircleShape eye;
#endif
};

#endif
