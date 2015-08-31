#include "stdafx.h"
#include "Secret.h"
#include "../Extras/utilities.h"

Fairy5::Fairy5() : Collectable(){
}

Fairy5::Fairy5(Level* l, float x_, float y_, You* yo) 
  : Collectable(l,x_,y_,20,30,yo) {
  eve=MISCE_1;
#ifndef COMPILE_NO_SF
  texture = getGraphic("Fairy5");
  fairy.setOrigin(width/2,height/2);
  fairy.setScale(-1,1);
#endif

}

void Fairy5::act() {
  if (you->holdingSecret1()) {
    float cx,cy;
    getObjectCenter(you,cx,cy);
    x = cx-width/2;
    y = cy-height/2;
  }
  else
    Collectable::act();
}

#ifndef COMPILE_NO_SF
void Fairy5::render(sf::RenderWindow & window) {
  fairy.setTexture(texture);
  fairy.setPosition(sf::Vector2f(getX1()+width,getY1()));
  window.draw(fairy);
}
#endif
