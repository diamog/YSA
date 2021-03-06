#ifndef ___SPEECHBUBBLE_H__
#define ___SPEECHBUBBLE_H__
#include "Actor.h"
#include "Codes.h"

#ifndef COMPILE_NO_SF
class SpeechBubble : public Actor{
 public:
  SpeechBubble();
  SpeechBubble(Level* l,std::string s,sf::Color c,float y_, EVE_CODE e = END_SPEECH);

  bool doesPause() {return false;}
  void act() {};
  void windowEvent(sf::Event& event);
  void render(sf::RenderWindow& window);

 private:
  bool isPaused;
  std::string message;
  unsigned int tick;
  unsigned int index;
  unsigned int start_index;
  sf::Color col;
  sf::Font font;
  sf::Text text;
  sf::Text next_text;
  sf::RectangleShape shape;
  EVE_CODE eve;
  unsigned int total_tick;
};
#endif
#endif
