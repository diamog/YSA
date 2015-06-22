#include "stdafx.h"
#include "ColorPlat.h"


ColorPlatform::ColorPlatform() : Platform(), Actor() {
}

ColorPlatform::ColorPlatform(Level* l, float x_,float y_,float w,float h,You* yo) : Platform(l,x_,y_,w,h,yo), Actor(l,x_,y_,w,h){
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(255,255,255));
#endif
}

void ColorPlatform::setColor(int r, int g, int b) {
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(r,g,b));
#endif
}

ColorPlat::ColorPlat() : ThinPlat(), Actor() {
  
}

ColorPlat::ColorPlat(Level* l, float x_,float y_,float w,You* yo) : ThinPlat(l,x_,y_,w,yo), Actor(l,x_,y_,w,3){
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(255,255,255));
#endif
}

void ColorPlat::setColor(int r, int g, int b) {
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(r,g,b));
#endif
}
