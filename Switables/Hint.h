#ifndef __HINT__H__
#define __HINT__H__

#include "Collectable.h"


class Hint : public Collectable {
 public:
  Hint();
  Hint(Level* l,float x_, float y_, float w, float h, You* yo, std::string m);

#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
  void activate() {};
 private:
  std::string message;

};

#endif
