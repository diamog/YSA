#ifndef __HINT__H__
#define __HINT__H__

#include "Collectable.h"


class Hint : public Collectable {
 public:
  Hint();
  Hint(float x_, float y_, float w, float h, You* yo, std::string m);

  void render(sf::RenderWindow& window);
 private:
  std::string message;

};

#endif
