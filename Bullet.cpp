#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet() : Actor(),Mover(){
  type = "";
}

Bullet::Bullet(Level* l,float x_, float y_, float w, float h, std::string t) :
  Actor(l,x_,y_,w,h), Mover(l,x_,y_,w,h) {
  type = t;
#ifndef COMPILE_NO_SF
  shape.setRadius(width/2);
  shape.setFillColor(sf::Color(255,255,0));
#endif
}

#ifndef COMPILE_NO_SF
void Bullet::render(sf::RenderWindow& window) {
	
  shape.setPosition(x,y);
  window.draw(shape);
}
#endif

