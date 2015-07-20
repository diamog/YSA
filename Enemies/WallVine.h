#ifndef __WALLVINE__H__
#define __WALLVINE__H__

#include <cmath>
#include "Vine.h"
#include "../Extras/utilities.h"

class WallVine : public Vine {
public:
  WallVine();
  WallVine(Level* l,int s,You* yo);
  void act();
  void render(sf::RenderWindow& window);

 protected:
  int side;
};

#endif
