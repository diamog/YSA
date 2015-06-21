#include "stdafx.h"
#include "ThinPlat.h"

ThinPlat::ThinPlat() : Platform() {
  isLeft=isRight=isUp=false;
}

ThinPlat::ThinPlat(Level* l, float x_,float y_,float w,You* yo) : Platform(l,x_,y_,w,3,yo){
  isLeft = isRight = isUp = false;
}
