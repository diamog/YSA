#ifndef COMPILE_NO_VB
#include "stdafx.h"
#endif

#include "Hint.h"

Hint::Hint() : Collectable() {
  message = "EMPTY";
}

Hint::Hint(Level* l, float x_, float y_, float w, float h, You* yo, std::string m) 
  : Collectable(l,x_,y_,w,h,yo) {
  message = m;
  eve = SPEECH;
}

#ifndef COMPILE_NO_SF
void Hint::render(sf::RenderWindow & window) {

}
#endif
