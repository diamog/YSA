#include <SFML/Graphics.hpp>

#ifndef __FILE_MENU_H__
#define __FILE_MENU_H__

class FileMenu {
 public:
  FileMenu();

  bool isChangeMenu(int& menu);
  void act();
  void render(sf::RenderWindow& window);
 private:
  void setChoice();
  sf::Font font;
  sf::Text title;
  sf::Text f1,f2,f3;
  sf::Text back;
  sf::RectangleShape select;
  int choice;
  bool isLeave;
  bool isDown,isUp,isLeft,isRight,isEnter;
};
#endif
