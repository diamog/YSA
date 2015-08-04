#include "stdafx.h"
#include "ThinPlat.h"
#include "../Enemies/Reverser.h"
#include "../Level.h"
ThinPlat::ThinPlat() : Actor(),Platform() {
  isLeft=isRight=isUp=false;
}

ThinPlat::ThinPlat(Level* l, float x_,float y_,float w,You* yo) :  Actor(l,x_,y_,w,3),Platform(l,x_,y_,w,3,yo){
  isLeft = isRight = isUp = false;
}

void ThinPlat::act() {
  
  Platform::act();
  #ifndef COMPILE_NO_SF
  if (you->getPlat()==this)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      you->setPosition(you->getX1(),getY1()+3-you->getHeight());
      you->setFall(getVal());
    }
  if (rev!=NULL)
    if (rev->getPlat()==this)
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
	rev->setPosition(rev->getX1(),getY2()-rev->getHeight()+level->getY());
	rev->setFall(getVal());
      }
#endif

}
