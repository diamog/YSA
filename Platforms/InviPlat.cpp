#include "stdafx.h"
#include "InviPlat.h"
#include "../Enemies/Reverser.h"
#include "../Level.h"
InviPlat::InviPlat() : Actor(),Platform() {
}

InviPlat::InviPlat(Level* l, float x_,float y_,float w,float h,You* yo) :  Actor(l,x_,y_,w,h),Platform(l,x_,y_,w,h,yo){
}

void InviPlat::render(sf::RenderWindow& window) {
#ifdef COMPILE_DEBUG
  Platform::render(window);
#endif
}

