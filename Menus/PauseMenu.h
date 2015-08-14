#include <SFML/Graphics.hpp>
#include "../You.h"
#include "../Graphics/ExtraBoard.h"
#ifndef __PAUSE_MENU_H__
#define __PAUSE_MENU_H__

class PauseMenu {
 public:
  PauseMenu();
  
  void setYou(You* yo) {you=yo;choice=0;setRectPos(select,cont);board.reset(you);}
  bool isChangeMenu(int& menu);
  void act();
  void render(sf::RenderWindow& window);
 private:
  You* you;
  void setChoice();
  sf::Font font;
  sf::Text cont;
  sf::Text options;
  sf::Text achieves;
  sf::Text quit;
  sf::RectangleShape background;
  sf::RectangleShape select;
  int choice;
  bool isLeave;
  bool isDown,isUp,isEnter;
  ExtraBoard board;
};
#endif
