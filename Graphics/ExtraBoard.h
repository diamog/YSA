
#include <SFML/Graphics.hpp>
#include "../You.h"
#include <vector>

#ifndef __EXTRA_BOARD_H__
#define __EXTRA_BOARD_H__

class ExtraBoard {
 public:
  ExtraBoard(float x_, float y_);

  void reset(You* you);

  void render(sf::RenderWindow& window);
 private:
  float x,y;
  std::vector<sf::RectangleShape> borders;
  std::vector<sf::CircleShape> extras;
};
#endif
