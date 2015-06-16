#include "Actor.h"
#include "Codes.h"
#include "You.h"

#ifndef __SWITCH__H__
#define __SWITCH__H__

class Switch : public Actor {
 public:
  Switch();
  Switch(Level* l, float x_, float y_, float w, float h, You* yo);

  void act();
  #ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
  #endif
 protected:
  You* you;
  EVENT_CODE eve;
};

#endif
