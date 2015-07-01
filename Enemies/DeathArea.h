#include "Death.h"

#ifndef __DEATHAREA__H__
#define __DEATHAREA__H__

class DeathArea : public Death {
 public:
  DeathArea();
  DeathArea(Level* l, float x_,float y_,float w,float h, You* yo);

#ifndef COMPILE_NO_SF
  void setHeight(float h) {Death::setHeight(h);shape.setSize(sf::Vector2f(width,height));}
  void render(sf::RenderWindow& window);
#endif

 protected:
#ifndef COMPILE_NO_SF
  sf::RectangleShape shape;
#endif
};

#endif
