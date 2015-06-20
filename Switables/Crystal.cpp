#include "stdafx.h"

#include "Crystal.h"

Crystal::Crystal() : Collectable() {
  type = "NULL";
}

Crystal::Crystal(Level* l, float x_, float y_, float w, float h, You* yo, std::string t) 
  : Collectable(l,x_,y_,w,h,yo) {
  type = t;
  eve = MISCE_1;
}


#ifndef COMPILE_NO_SF
void Crystal::render(sf::RenderWindow & window) {

}
#endif
