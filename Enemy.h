#include "Mover.h"
#include "Death.h"

#ifndef __ENEMY__H__
#define __ENEMY__H__

class Enemy : public Mover, public Death{
 public:
  Enemy();
  Enemy(Level* l, float x_,float y_,float w,float h, You* yo, int health);
  
#ifndef COMPILE_NO_SF
  void act(sf::Event& event);
#endif
  virtual void hit();
 protected:
  int hp;
  
};

#endif
