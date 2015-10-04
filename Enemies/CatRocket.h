#ifndef __CATROCKET__H__
#define __CATROCKET__H__

#include <cmath>
#include "../Enemies/Death.h"
#include "../Bullet.h"
#include "../Extras/utilities.h"

class CatRocket : public Bullet, public Death {
public:
  CatRocket();
  CatRocket(Level* l,float x_, float y_,int index,int max,You* yo);
  void act();
  bool isGone() const {return isDead;}

  void render(sf::RenderWindow& window);
protected:
  float vel;
  bool isDead;
  sf::RectangleShape base;
  float a,b,c;
  float rate;
  float ticks;
  int part;
};

#endif
