#ifndef __THIN_PLATFORM__H__
#define __THIN_PLATFORM__H__

#include "Platform.h"

class ThinPlat : public Platform {
 public:
  ThinPlat();
  ThinPlat(Level* l, float x_,float y_,float w,You* yo);

  void act();
};

#endif
