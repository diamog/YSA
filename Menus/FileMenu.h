#include <SFML/Graphics.hpp>
#include "../You.h"

#ifndef __FILE_MENU_H__
#define __FILE_MENU_H__

class FileMenu {
 public:
  FileMenu(You* you1, You* you2, You* you3);

  bool isChangeMenu(int& menu);
  void act();
  void render(sf::RenderWindow& window);
 private:
  void setupFileMenu(int index, float x1, You* you);
  void setChoice();
  sf::Font font;
  sf::Text title;
  sf::Text f[3];
  sf::Text diff[3];
  sf::Text death[3];
  sf::Text back;
  sf::RectangleShape b[3];
  sf::RectangleShape select;
  int choice;
  bool isLeave;
  bool isDown,isUp,isLeft,isRight,isEnter;
};
#endif
