#ifndef __PBULLET2__H__
#define __PBULLET2__H__

#include <cmath>
#include "PBullet.h"
#include "../Extras/utilities.h"

class PBullet2 : public PBullet {
public:
  PBullet2();
  PBullet2(Level* l,float x_, float y_,You* yo,float angle);
};

#endif
