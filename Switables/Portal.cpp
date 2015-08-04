#include "stdafx.h"

#include "Portal.h"
#include "../Extras/utilities.h"

Portal::Portal() : Switch(){
}

Portal::Portal(Level* l, float x_, float y_, float w, float h,You* yo,EVE_CODE num) : Switch(l,x_,y_,w,h,yo) {
  eve = num;
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(150,0,150));
  shape.setRadius(1);
  shape.setScale(width/2,height/2);
  /*shape.setRadius(height/2);
  if (width<height)
    shape.setScale(1,height/width);
  else 
  shape.setScale(width/height,1);*/
#endif
}

#ifndef COMPILE_NO_SF
void Portal::render(sf::RenderWindow& window) {
  shape.setPosition(getX1(),getY1());
  window.draw(shape);
} 
#endif
