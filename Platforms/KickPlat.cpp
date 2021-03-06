#include "stdafx.h"
#include "KickPlat.h"
#include "../Enemies/Reverser.h"
#include "../Level.h"
KickPlat::KickPlat() : Actor(),Platform() {}

KickPlat::KickPlat(Level* l, float x_,float y_,float w,float h,You* yo,
                   bool isL,bool isR) :  Actor(l,x_,y_,w,h),
                                         Platform(l,x_,y_,w,h,yo){
  kickLeft=isL;
  kickRight=isR;
}

#ifndef COMPILE_NO_SF
void KickPlat::render(sf::RenderWindow& window) {
  Platform::render(window);
  if (kickLeft) {
    for (float i=getY1();i<getY1()+height;i+=20) {
      sf::Vertex line[] =
      {
	sf::Vertex(sf::Vector2f(getX1(), i)),
	sf::Vertex(sf::Vector2f(getX1()-10, i+10))
      };
    window.draw(line,2,sf::Lines);

    }
  }
  if (kickRight) {
    for (float i=getY1();i<getY1()+height;i+=20) {
      sf::Vertex line[] =
      {
	sf::Vertex(sf::Vector2f(getX1()+width, i)),
	sf::Vertex(sf::Vector2f(getX1()+width+10, i+10))
      };
    window.draw(line,2,sf::Lines);

    }
  }
}
#endif
