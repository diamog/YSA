#ifndef ___SPEECHBUBBLE_H__
#define ___SPEECHBUBBLE_H__
#include "Actor.h"
#include "Codes.h"

#ifndef COMPILE_NO_SF
class SpeechBubble : public Actor{
 public:
  SpeechBubble();
  SpeechBubble(Level* l,std::string s,sf::Color c,EVE_CODE e = END_SPEECH);

  bool doesPause() {return false;}
  void act();
  void windowEvent(sf::Event& event);
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
  EVE_CODE eve;

};
#endif
#endif
