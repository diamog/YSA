#ifndef __VERTICLE_PLATFORM__H__
#define __VERTICLE_PLATFORM__H__

#include "ThinPlat.h"
#include "../Mover.h"

class VertPlat : public ThinPlat, public Mover {
public:
  VertPlat();
  VertPlat(Level* l, float x_,float y_,float w,You* yo,bool isV, int dir=1);

  void act();
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
  int getVal() {if (isVert) return vel;return 0;}
  void hitDetector(int dir);

private:
  bool isVert;
  float vel;
};

#endif
