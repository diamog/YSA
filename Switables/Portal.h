#include "Switch.h"
#include "../Codes.h"

#ifndef __PORTAL__H__
#define __PORTAL__H__

class Portal : public Switch {
public:
  Portal();
  Portal(Level* l, float x_, float y_, float w, float h,You* yo, EVE_CODE num);

#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif

protected:
#ifndef COMPILE_NO_SF
  sf::CircleShape shape;
#endif

};

#endif
