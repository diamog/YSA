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
              std::string t,ColorBoss* b, int c);
  void act();

protected:
  ColorBoss* target;
  int color;
};

#endif
