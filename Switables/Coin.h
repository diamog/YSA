#ifndef __COIN__H__
#define __COIN__H__

#include "Collectable.h"


class Coin : public Collectable {
 public:
  Coin();
  Coin(Level* l,float x_, float y_, You* yo, EVE_CODE e);

#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
 private:
  
#ifndef COMPILE_NO_SF
  sf::CircleShape shape;
#endif
};

#endif
