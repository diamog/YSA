

#include "stdafx.h"
#include "Detector.h"
#include "Extras/utilities.h"

Detector::Detector() : Actor() {
  actors = NULL;
}
Detector::Detector(Level* l, float x_,float y_,float w,float h,std::vector<Actor*>* acts) : Actor(l,x_,y_,w,h){
  actors = acts;
}

void Detector::act() {
  for (unsigned int i=0;i<actors->size();i++)
    if (isRectangularHit(this,(*actors)[i])) {
      (*actors)[i]->hitDetector(getApproachDirection((*actors)[i],this));
    }
}

#ifndef COMPILE_NO_SF
void Detector::render(sf::RenderWindow& window) {
#ifdef COMPILE_DEBUG
  sf::CircleShape shape(width/2);
  shape.setPosition(getX1(),getY1());
  shape.setFillColor(sf::Color(0,0,0));
  window.draw(shape);
#endif
}
#endif
