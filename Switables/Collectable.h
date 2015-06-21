#include "../Actor.h"
#include "../Codes.h"
#include "../You.h"

#ifndef __COLLECTABLE__H__
#define __COLLECTABLE__H__

class Collectable : public Actor {
 public:
  Collectable();
  Collectable(Level* l, float x_, float y_, float w, float h, You* yo);

#ifndef COMPILE_NO_SF
  void act(sf::Event& event);
  void render(sf::RenderWindow& window);
#endif

  virtual void activate() = 0;
 protected:
  You* you;
  EVENT_CODE eve;
};

#endif
