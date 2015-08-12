#include <SFML/Graphics.hpp>
#include "../You.h"

#ifndef __PAUSE_MENU_H__
#define __PAUSE_MENU_H__

class PauseMenu {
 public:
  PauseMenu();

  bool isChangeMenu(int& menu);
  void act(You* you);
  void render(sf::RenderWindow& window);
 private:
  void setChoice();
  sf::Font font;
  sf::Text c;
  sf::Text start;
  sf::Text options;
  sf::Text achieves;
  sf::RectangleShape background;
  sf::RectangleShape select;
  int choice;
  bool isLeave;
  bool isDown,isUp,isEnter;
};
#endif
