#include "stdafx.h"

#include "Save.h"
#include "../Extras/utilities.h"

Save::Save() : Switch(){
  you = NULL;
}

Save::Save(Level* l, float x_, float y_, float w, You* yo,S_CODE save) : 
  Switch(l,x_,y_,w,w,yo) {
	x=x_;y=y_;width=height=w;
  eve = SAVE;
	identity = save;
#ifndef COMPILE_NO_SF
	shape.setPosition(x,y);
	shape.setFillColor(sf::Color(0,0,255));
	shape.setRadius(width/2);
#endif
}

#ifndef COMPILE_NO_SF
void Save::render(sf::RenderWindow& window) {
  window.draw(shape);
} 
#endif
