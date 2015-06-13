#include "Actor.h"
#include "Codes.h"
#include "You.h"

#ifndef __COLLECTABLE__H__
#define __COLLECTABLE__H__

class Collectable : public Actor {
 public:
  Collectable();
  Collectable(float x_, float y_, float w, float h, You* yo);

  void act();
  void render(sf::RenderWindow& window);

 protected:
  You* you;
  EVENT_CODE eve;
};

#endif
