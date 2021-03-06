#include "../Actor.h"
#include "../Codes.h"
#include "../You.h"

#ifndef __COLLECTABLE__H__
#define __COLLECTABLE__H__

class Collectable : public Actor {
 public:
  Collectable();
  Collectable(Level* l, float x_, float y_, float w, float h, You* yo);

  void act();

  virtual void activate() {};
 protected:
  You* you;
  EVENT_CODE eve;
};

#endif
