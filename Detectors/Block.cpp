#include "stdafx.h"
#include "Block.h"
#include "Extras/utilities.h"
#include "../Level.h"
Block::Block() : Actor(),BigEye(),Platform() {

}
Block::Block(Level* l, float x_,float y_,int blockType, 
	     SmallEye* e,You* yo, int d) : 
  Actor(l,x_,y_,80,80), BigEye(l,x_,y_,NOTHING,e), Platform(l,x_,y_,80,80,yo){
  dir = d;
  if (blockType==0)
    shape.setFillColor(sf::Color(170,0,170));
  else if (blockType==1)
    shape.setFillColor(sf::Color(0,150,0));
  shape.setSize(sf::Vector2f(width,height));
  int amm=6;
  float size = (amm-1)/2*width/amm;
  arrow.setRadius(size);
  arrow.setPointCount(3);
  arrow.setOrigin(size,size);
  arrow.setFillColor(sf::Color(180,180,180));
}

void Block::act() {
  Platform::act();
  BigEye::act();
}
#ifndef COMPILE_NO_SF
void Block::render(sf::RenderWindow& window) {
  shape.setPosition(getX1(),getY1());
  window.draw(shape);
  arrow.setRotation(dir*90);
  arrow.setPosition(getX1()+width/2,getY1()+height/2);
  window.draw(arrow);
   
  //DRAW ARROW
  
}
#endif
