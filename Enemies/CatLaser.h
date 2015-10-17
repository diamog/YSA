#ifndef __CATLASER__H__
#define __CATLASER__H__

#include <cmath>
#include "../Enemies/Death.h"
#include "../Bullet.h"
#include "../Extras/utilities.h"

class CatBoss;

class CatLaser : public Bullet, public Death {
public:
  CatLaser();
  CatLaser(Level* l,float x_, float y_,You* yo,CatBoss* b);
  void act();

  void render(sf::RenderWindow& window);
protected:
  CatBoss* boss;
  float col;
  float vel;
  int dir;
  float rate;
  float len;
  sf::RectangleShape base;
  sf::RectangleShape laser;
  sf::CircleShape pointer;
  float ticks;
  int part;
};

#endif
