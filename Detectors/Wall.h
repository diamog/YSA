#ifndef __WALL__H__
#define __WALL__H__

#include <vector>
#include "BigEye.h"
#include "../Platforms/Platform.h"

class Wall : public BigEye, public Platform{
 public:
  Wall();
  Wall(Level* l,float x_,float y_,float w,float h, 
	SmallEye* e, You* yo, bool on);
  void act();
  void turn() {isVis=!isVis;}
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
 protected:
  bool isVis;
  int alpha;
};

#endif
