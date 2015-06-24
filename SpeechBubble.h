#ifndef ___SPEECHBUBBLE_H__
#define ___SPEECHBUBBLE_H__
#include "Actor.h"

#ifndef COMPILE_NO_SF
class SpeechBubble : public Actor{
 public:
  SpeechBubble();
  SpeechBubble(std::string s,sf::Color c);

  bool doesPause() {return false;}
  void render(sf::RenderWindow& window);

 private:
  bool isPaused;
  std::string message;
  int index;
  int start_index;
  sf::Color col;
  sf::Font font;
  sf::Text text;
  sf::RectangleShape shape;

};
#endif
#endif
