#ifndef __VINE__H__
#define __VINE__H__

#include <cmath>
#include "PBullet.h"
#include "../Extras/utilities.h"

class Vine : public PBullet {
public:
  Vine();
  Vine(Level* l,float x_,You* yo);
  void act();
  void render(sf::RenderWindow& window);
 protected:
  float ticks;
  sf::RectangleShape shape2;
};

#endif
