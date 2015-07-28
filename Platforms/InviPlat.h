#ifndef __INVISIBLE_PLATFORM__H__
#define __INVISIBLE_PLATFORM__H__

#include "Platform.h"

class InviPlat : public Platform {
 public:
  InviPlat();
  InviPlat(Level* l, float x_,float y_,float w,float h, You* yo);

  void render(sf::RenderWindow& window);
};

#endif
