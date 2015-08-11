#include "stdafx.h"
#include "Stem.h"
#include "../Enemies/Reverser.h"
#include "../Level.h"
Stem::Stem() : Actor(),Platform() {
  isDown=isUp=false;
}

Stem::Stem(Level* l, float x_,float y_,float cx_,float w,float h,You* yo,int d) :  Actor(l,x_,y_,w,h),Platform(l,x_,y_,w,h,yo){
  isDown = isUp = false;
  dir=1;
  cx=cx_;
  setPumpDir(d);
  isDead=false;
  vine = getGraphic("Vine");
  wiltedvine = getGraphic("DeadVine"); 
  stem.setOrigin(w/2,h/2);
}

void Stem::act() {
  Platform::act();
}
void Stem::setPumpDir(int d) {
  if (d==1) {
    x=cx-width;
  }
  else
    x=cx;
}
#ifndef COMPILE_NO_SF
void Stem::render(sf::RenderWindow& window) {
  /*float x1,x2;
  if (dir==-1) {
    x1=getX1();
    x2=getX2();
  }
  else {
    x1=getX2();
    x2=getX1();
  }
  sf::Color c = sf::Color(0,160,0);
  if (isDead)
    c = sf::Color(200,160,0);
  sf::Vertex line[] = 
  {
    sf::Vertex(sf::Vector2f(x1,getY1()),c),
    sf::Vertex(sf::Vector2f(x2,getY2()),c)
  };
  window.draw(line,2,sf::Lines);
  */
  stem.setPosition(getX1()+width/2,getY1()+height/2);
  if (isDead)
    stem.setTexture(wiltedvine);
  else
    stem.setTexture(vine);
  if (dir==-1)
    stem.setRotation(-90);
  else
    stem.setRotation(0);
  window.draw(stem);
}
#endif
