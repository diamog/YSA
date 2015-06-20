#include "stdafx.h"
#include "ThinPlat.h"

ThinPlat::ThinPlat() : Platform() {
  isLeft=isRight=false;
  isDown=false;
}

ThinPlat::ThinPlat(Level* l, float x_,float y_,float w,You* yo) : Platform(l,x_,y_,w,5,yo){
  isLeft = isRight = isDown =  false;
}
