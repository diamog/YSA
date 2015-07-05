#include "stdafx.h"
#include "Hint.h"

Hint::Hint() : Collectable(){
  message = "EMPTY";
}

Hint::Hint(Level* l, float x_, float y_, float w, You* yo, std::string m, int c) 
  : Collectable(l,x_,y_,w,w,yo) {
  code=c;
  message = m;
  eve = SPEECH;
#ifndef COMPILE_NO_SF
  shape.setRadius(width/2);
  shape.setFillColor(sf::Color(0,206,209));

  font.loadFromFile("Fonts/arial.ttf");
  mark.setFont(font);
  mark.setString("?");
  mark.setCharacterSize(width);
  mark.setColor(sf::Color(160,32,240));
#endif

}

#ifndef COMPILE_NO_SF
void Hint::render(sf::RenderWindow & window) {
  mark.setPosition(getX1()+width/4,getY1()-width/10);
  shape.setPosition(sf::Vector2f(getX1(),getY1()));
  if (!you->boss1()) {
    int color1 = 206*.72+209*.07;
    int color2 = 160*.21+32*.72+240*.07;
    shape.setFillColor(sf::Color(color1,color1,color1));
    mark.setColor(sf::Color(color2,color2,color2));
  }
  else {
    shape.setFillColor(sf::Color(0,206,209));
    mark.setColor(sf::Color(160,32,240));
  }
  window.draw(shape);
  window.draw(mark);
}
#endif
