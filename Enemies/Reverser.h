#include "Enemy.h"
#ifndef __REVERSER__H__
#define __REVERSER__H__

class Reverser : public Enemy, You{
 public:
  Reverser();
  Reverser(Level* l,You* yo,bool isVMirror);
	void act() {}
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
 protected:
  bool isVertMirror;
  
};

#endif
