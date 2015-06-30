#include "stdafx.h"
#include "ColorPlat.h"


ColorPlatform::ColorPlatform() : Actor(),Platform() {
}

ColorPlatform::ColorPlatform(Level* l, float x_,float y_,float w,float h,You* yo) :  Actor(l,x_,y_,w,h), Platform(l,x_,y_,w,h,yo){
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(255,255,255));
#endif
}

void ColorPlatform::setColor(int r, int g, int b) {
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(r,g,b));
#endif
}

ColorPlat::ColorPlat() : Actor(),ThinPlat() {
  
}

ColorPlat::ColorPlat(Level* l, float x_,float y_,float w,You* yo) : Actor(l,x_,y_,w,3),ThinPlat(l,x_,y_,w,yo) {
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(255,255,255));
#endif
}

void ColorPlat::setColor(int r, int g, int b) {
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(r,g,b));
#endif
}
