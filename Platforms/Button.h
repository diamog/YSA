#ifndef __BUTTON__H__
#define __BUTTON__H__

#include "ThinPlat.h"

class Button : public Platform {
 public:
  Button();
  Button(Level* l, float x_,float y_,You* yo,EVE_CODE e);

  void act();
  void render(sf::RenderWindow& window);
 protected:
  bool isOn;
  EVE_CODE eve;
};

#endif
