#include "Switch.h"
#include "../Codes.h"
#include "../You.h"

#ifndef __REDSWITCH__H__
#define __REDSWITCH__H__

class RedSwitch : public Switch {
public:
  RedSwitch();
  RedSwitch(Level* l, float x_, float y_, float w, You* yo, EVE_CODE num);

  void act();
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
protected:
#ifndef COMPILE_NO_SF
  sf::RectangleShape shape;
#endif

};

#endif
