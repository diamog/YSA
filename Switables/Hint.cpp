#include "stdafx.h"
#include "Hint.h"

Hint::Hint() : Collectable(){
  message = "EMPTY";
}

Hint::Hint(Level* l, float x_, float y_, float w, You* yo, std::string m) 
  : Collectable(l,x_,y_,w,w,yo) {
  message = m;
  eve = SPEECH;
#ifndef COMPILE_NO_SF
  shape.setRadius(width/2);
  shape.setFillColor(sf::Color(0,206,209));
  shape.setPosition(sf::Vector2f(x,y));

  font.loadFromFile("Fonts/arial.ttf");
  mark.setFont(font);
  mark.setString("?");
  mark.setCharacterSize(width);
  mark.setColor(sf::Color(160,32,240));
  mark.setPosition(x+width/4,y-width/10);
#endif

}

#ifndef COMPILE_NO_SF
void Hint::render(sf::RenderWindow & window) {
  window.draw(shape);
  window.draw(mark);
}
#endif
