#include "Mover.h"
#include "Death.h"

#ifndef __ENEMY__H__
#define __ENEMY__H__

class Enemy : public Death, public Mover{
 public:
  Enemy();
  Enemy(Level* l, float x_,float y_,float w,float h, You* yo);
  

 protected:
};

#endif
