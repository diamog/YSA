#include "Actor.h"
#include "You.h"
#ifndef __DEATH__H__
#define __DEATH__H__

class Death : public virtual Actor {
 public:
  Death();
  Death(Level* l, float x_,float y_,float w,float h, You* yo);

#ifndef COMPILE_NO_SF  
  void act(sf::Event& event);
#endif
 protected:
  You* you;
};

#endif
