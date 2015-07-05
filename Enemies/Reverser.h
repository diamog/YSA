#include "Death.h"
#ifndef __REVERSER__H__
#define __REVERSER__H__

class Reverser : public Death, public You{
 public:
  Reverser();
  Reverser(Level* l,You* yo,bool isVMirror);
  void act();
  float getLastX1() const {return You::getLastX1();};
  float getLastX2() const {return You::getLastX2();};
  float getLastY1() const {return You::getLastY1();};
  float getLastY2() const {return You::getLastY2();};

#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
 protected:
  bool isVertMirror;
};

#endif
