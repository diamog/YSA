#include "stdafx.h"
#include "ThinPlat.h"

ThinPlat::ThinPlat() : Platform(), Actor() {
  isLeft=isRight=isUp=false;
}

ThinPlat::ThinPlat(Level* l, float x_,float y_,float w,You* yo) : Platform(l,x_,y_,w,3,yo), Actor(l,x_,y_,w,3){
  isLeft = isRight = isUp = false;
}

void ThinPlat::act() {
  Platform::act();
#ifndef COMPILE_NO_SF
  if (you->getPlatX1()==getX1()&& you->getPlatX2()==getX2())
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      you->setPosition(you->getX1(),getY2()-(you->getY2()-you->getY1()));
#endif
}
