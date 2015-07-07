#ifndef __KICK_PLATFORM__H__
#define __KICK_PLATFORM__H__

#include "Platform.h"

class KickPlat : public Platform {
 public:
  KickPlat();
  KickPlat(Level* l, float x_,float y_,float w,float h,You* yo,bool isL, bool isR);

#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
};

#endif
