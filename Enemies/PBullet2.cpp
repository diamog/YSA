#include "stdafx.h"
#include "PBullet2.h"
#include "../Extras/utilities.h"
PBullet2::PBullet2() : Actor(),PBullet() {
}
PBullet2::PBullet2(Level* l,float x_, float y_,You* yo, float ang) 
  : Actor(l,x_,y_,7,7),PBullet(l,x_,y_,yo,ang,NULL) {
  vel=4;
}
