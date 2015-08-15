#ifndef __SECRET__H__
#define __SECRET__H__

#include "Collectable.h"


class Fairy5 : public Collectable {
 public:
  Fairy5();
  Fairy5(Level* l,float x_, float y_, You* yo);

  void act();

#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
 private:
  
#ifndef COMPILE_NO_SF
  sf::Texture texture;
  sf::Sprite fairy;
#endif
};

#endif
