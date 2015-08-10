#ifndef __CBULLET__H__
#define __CBULLET__H__

#include <cmath>
#include "../Enemies/Death.h"
#include "../Bullet.h"
#include "../Extras/utilities.h"
#include "SmallEye.h"

class CBullet : public Bullet, public Death {
public:
  CBullet();
  CBullet(Level* l,float x_, float y_,You* yo,SmallEye* e);

  void act();
  void setDead() {isDead=true;}
  bool isGone() const {return isDead;}
  int getVal() const {return dir;}
protected:
  int dir;
  float vel;
  bool isDead;
  SmallEye* eye;
};

#endif
