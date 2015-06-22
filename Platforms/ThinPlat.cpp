#include "stdafx.h"
#include "ThinPlat.h"

ThinPlat::ThinPlat() : Platform(), Actor() {
  isLeft=isRight=isUp=false;
}

ThinPlat::ThinPlat(Level* l, float x_,float y_,float w,You* yo) : Platform(l,x_,y_,w,3,yo), Actor(l,x_,y_,w,3){
  isLeft = isRight = isUp = false;
}
