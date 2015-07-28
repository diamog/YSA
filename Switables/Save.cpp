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
  shape.setFillColor(sf::Color(0,0,255));
  shape.setRadius(width/2);
#endif
  save_ticks=300;
}
void Save::act() {
  rev=NULL;
  if (you->getDead())
    save_ticks=0;
  if (save_ticks>=300) {
    Switch::act();
  }
  else
    save_ticks++;
}
void Save::activate() {
  save_ticks=0;
}
#ifndef COMPILE_NO_SF
void Save::render(sf::RenderWindow& window) {
  shape.setPosition(getX1(),getY1());
  if (!you->boss1()) 
    shape.setFillColor(sf::Color(255*.07,255*.07,255*.07));
  else
    shape.setFillColor(sf::Color(0,0,255));
  window.draw(shape);
} 
#endif
