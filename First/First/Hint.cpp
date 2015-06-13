#include "stdafx.h"
#include "Hint.h"

Hint::Hint() : Collectable() {
  message = "EMPTY";
}

Hint::Hint(float x_, float y_, float w, float h, You* yo, std::string m) 
  : Collectable(x_,y_,w,h,yo) {
  message = m;
  eve = SPEECH;
}

void Hint::render(sf::RenderWindow & window) {

}
