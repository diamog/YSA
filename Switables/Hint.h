#ifndef __HINT__H__
#define __HINT__H__

#include "Collectable.h"


class Hint : public Collectable {
 public:
  Hint();
  Hint(Level* l,float x_, float y_, float w, You* yo, std::string m, int c);

#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
  std::string getMessage() {return message;}
  int getVal() {return code;}
  void activate() {};
 private:
  std::string message;
  int code;
#ifndef COMPILE_NO_SF
	
  sf::CircleShape shape;
  sf::Font font;
  sf::Text mark;

#endif
};

#endif
