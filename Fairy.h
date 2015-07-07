#include "Actor.h"
#ifndef __FAIRY_H__
#define __FAIRY_H__
class Fairy : public Actor {
public:
  Fairy() : Actor() {}
  Fairy(Level* l,float x_,float y_);
  
  void act();

#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif

  void turnOn(int i);
  bool doesPause() {return false;}
  
  void kill();
 protected:
  int val;
  int dir;
  float central_y;
  float angle;
  float angle0;
#ifndef COMPILE_NO_SF
  sf::CircleShape shape;
#endif  
};
#endif
