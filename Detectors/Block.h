#ifndef __BLOCK__H__
#define __BLOCK__H__

#include <vector>
#include "BigEye.h"
#include "../Platforms/Platform.h"
class Block : public BigEye, public Platform{
 public:
  Block();
  Block(Level* l,float x_,float y_,int blockType, 
	SmallEye* e, You* yo, int d);
  void act();
  void rotate(int d) {dir+=d;dir=(dir+4)%4;}
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
 protected:
  sf::CircleShape arrow;
};

#endif
