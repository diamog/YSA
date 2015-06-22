#ifndef __COLOR_PLATFORM__H__
#define __COLOR_PLATFORM__H__

#include "ThinPlat.h"
#include "Platform.h"
class ColorPlatform : public Platform {
 public:
  ColorPlatform();
  ColorPlatform(Level* l, float x_, float y_, float w, float h, You* yo);

  void setColor(int r, int g, int b);
};

class ColorPlat : public ThinPlat {
 public:
  ColorPlat();
  ColorPlat(Level* l, float x_,float y_,float w,You* yo);

  void setColor(int r, int g, int b);
};

#endif
