#include "../Actor.h"
#include "../Codes.h"
#include "../You.h"

#ifndef __SWITCH__H__
#define __SWITCH__H__

class Switch : public Actor {
 public:
  Switch();
  Switch(Level* l, float x_, float y_, float w, float h, You* yo);

  void act();
  virtual void activate() {};
protected:
  You* you;
  EVENT_CODE eve;
};

#endif
