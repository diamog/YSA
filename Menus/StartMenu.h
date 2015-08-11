#include <SFML/Graphics.hpp>

#ifndef __START_MENU_H__
#define __START_MENU_H__

class StartMenu {
 public:
  StartMenu();

  bool isChangeMenu(int& menu);
  void act();
  void render(sf::RenderWindow& window);
 private:
  void setChoice();
  sf::Font font;
  sf::Text title;
  sf::Text start;
  sf::Text options;
  sf::Text achieves;
  sf::RectangleShape select;
  int choice;
  bool isLeave;
  bool isDown,isUp,isEnter;
};
#endif
