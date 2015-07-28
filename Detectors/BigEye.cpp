#include "stdafx.h"
#include "BigEye.h"
#include "Extras/utilities.h"
#include "../Level.h"
#include <cmath>
BigEye::BigEye() : Actor(),Detector() {
  eye = NULL;
}
BigEye::BigEye(Level* l, float x_,float y_,EVE_CODE eve_, SmallEye* e) : 
  Actor(l,x_,y_,70,70), Detector(l,x_,y_,70,70,NULL){
  eye=e;
  eve=eve_;
  dir=-1;
  shape2.setRadius(width/2);
  shape2.setFillColor(sf::Color(220,200,0));
  isHit=false;
}

bool BigEye::isInside() {
  float ex,ey;
  float cx,cy;
  getObjectCenter(this,cx,cy);
  getObjectCenter(eye,ex,ey);
  return (sqrt(pow(cx-ex,2)+pow(cy-ey,2))<8);
}
void BigEye::act() {
  if (isRectangularHit(this,eye)) {
    if (!isHit) {
      if (dir==-2) { 
	eye->reset();
	return;
      }
      else {
	if (isInside()) {
	  if (dir==-1)
	    eye->setReset(x+width/2,y+height/2);
	  eye->hitDetector(dir);
	  level->sendEvent(eve,NULL);
	  isHit=true;
	}
      }
    }
  }
  else
    isHit=false;
}

#ifndef COMPILE_NO_SF
void BigEye::render(sf::RenderWindow& window) {
  shape2.setPosition(getX1(),getY1());
  window.draw(shape2);
}
#endif
