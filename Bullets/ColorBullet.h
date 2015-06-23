#ifndef __COLORBULLET__H__
#define __COLORBULLET__H__

#include <cmath>
#include "../Bullet.h"
#include "../Extras/utilities.h"
#include "../Enemies/ColorBoss.h"

class ColorBullet : public Bullet {
public:
  ColorBullet();
  ColorBullet(Level* l,float x_, float y_, float w, float h,
              std::string t,ColorBoss* b);
#ifndef COMPILE_NO_SF
  void act(sf::Event& event);
#endif

protected:
  ColorBoss* target;
	int color;
};

#endif
