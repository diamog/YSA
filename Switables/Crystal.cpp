#include "stdafx.h"

#include "Crystal.h"

Crystal::Crystal() : Collectable() {
  type = "NULL";
  color=0;
}

Crystal::Crystal(Level* l, float x_, float y_, float w, float h, You* yo, std::string t) 
  : Collectable(l,x_,y_,w,h,yo) {
  type = t;
  color=255;
  eve = MISCE_1;
#ifndef COMPILE_NO_SF
	shape.setRadius(width);
	shape.setScale(1,height/width);
  shape.setFillColor(sf::Color(color*(type=="red"),color*(type=="green"),
                            color*(type=="blue")));
  shape.setPosition(x,y);
#endif

}


#ifndef COMPILE_NO_SF
void Crystal::render(sf::RenderWindow & window) {
  window.draw(shape);
}
#endif

void Crystal::activate() {
  color-=15;
	if (color<0)
		color=0;
  //randomize position
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(color*(type=="red"),color*(type=="green"),
                            color*(type=="blue")));
  shape.setPosition(x,y);
#endif
}
