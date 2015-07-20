#include "Switch.h"

#ifndef __ANTIGRAVITY__H__
#define __ANTIGRAVITY__H__

class AntiGravity : public Switch {
public:
  AntiGravity();
  AntiGravity(Level* l, float x_, float y_, float w, float h,You* yo);
  
  void activate();
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window) {};
#endif
protected:
  bool isOn;
};

#endif
