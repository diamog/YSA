#include "Switch.h"
#include "../Codes.h"

#ifndef __FOLLOWERFACTORY__H__
#define __FOLLOWERFACTORY__H__

class FollowerFactory : public Switch {
public:
  FollowerFactory();
  FollowerFactory(Level* l, float x_, float y_, float w, float h,You* yo, int c, std::vector<Actor*>* a);
  
  void activate();
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window) {};
#endif
protected:
  int count;
  bool isOn;
  std::vector<Actor*>* actors;
};

#endif
