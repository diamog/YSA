#include "stdafx.h"
#include "Death.h"
#include "../Extras/utilities.h"
#include "../You.h"

Death::Death() : Actor() {
  you = NULL;
}

Death::Death(Level* l, float x_,float y_,float w,float h, You* yo) : Actor(l,x_,y_,w,h) {
  you = yo;
}

void Death::act() {
  if (isRectangularHit(you,this)) {
    you->die();
  }
}
