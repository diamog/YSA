#ifndef __PBULLET__H__
#define __PBULLET__H__

#include <cmath>
#include "../Enemies/Death.h"
#include "../Bullet.h"
#include "../Extras/utilities.h"
#include "../Platforms/Stem.h"

class PBullet : public Bullet, public Death {
public:
  PBullet();
  PBullet(Level* l,float x_, float y_,You* yo,float angle, 
	  std::vector<Stem*>* s);
  void act();
  bool isGone() const {return isDead;}
protected:
  std::vector<Stem*>* stems;
  float angle;
  float vel;
  bool isDead;
};

#endif
