#include "../Actor.h"
#include "../Level.h"
#ifndef __COLORREMOVE_H__
#define __COLORREMOVE_H__

class ColorRemove : public Actor {
 public:
  ColorRemove() : Actor() {};
  ColorRemove(Level* l,sf::Color col,float x_, float y_);
  void act() {rad+=10;if (rad>700) level->sendEvent(KILL,this);};
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
 private:
  float rad;
  Level* mylevel;
#ifndef COMPILE_NO_SF
  sf::CircleShape shape;
#endif
};
#endif
