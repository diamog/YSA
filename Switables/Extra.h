#ifndef __EXTRA__H__
#define __EXTRA__H__

#include "Collectable.h"


class Extra : public Collectable {
 public:
  Extra();
  Extra(Level* l,float x_, float y_, float w, float h, You* yo);

#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
  
private:

#ifndef COMPILE_NO_SF
  sf::CircleShape shape;
#endif
};

#endif
