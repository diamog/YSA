#include "Actor.h"

#ifndef __MOVER__H__
#define __MOVER__H__

class Mover : public virtual Actor {
 public:
  Mover();
  Mover(Level* l, float x_,float y_,float w,float h);

  float getLastX1() const {return lastx;}
  float getLastX2() const {return lastx+width;}
  float getLastY1() const {return lasty;}
  float getLastY2() const {return lasty+height;}
	
#ifndef COMPILE_NO_SF
  void act(sf::Event& event);
#endif

 protected:
  float lastx,lasty;
};

#endif
