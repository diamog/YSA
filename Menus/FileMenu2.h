#include <SFML/Graphics.hpp>
#include "../You.h"

#ifndef __FILE_MENU2_H__
#define __FILE_MENU2_H__

class FileMenu2 {
 public:
  FileMenu2();

  void setYou(You* you);
  bool isChangeMenu(int& menu);
  void act();
  void render(sf::RenderWindow& window);
 private:
  You* you_;
  void setChoice();
  sf::Font font;
  sf::Text title;
  sf::Text file;
  sf::Text diff;
  sf::Text death;
  sf::Text new_game;
  sf::Text cont;
  sf::Text erase;
  sf::Text back;
  sf::RectangleShape border;
  sf::RectangleShape b;
  sf::RectangleShape btop;
  sf::RectangleShape select;
  int choice;
  bool isLeave;
  bool isDown,isUp,isLeft,isRight,isEnter;
};
#endif
