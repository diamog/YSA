#include "stdafx.h"

#include "ExtraBoard.h"
#include <cmath>
#include "../Codes.h"
ExtraBoard::ExtraBoard(float x_, float y_) {
  x=x_;y=y_;
  int mid = floor((FINALROOM+START)*1.0/2);
  for (int i=START;i<FINALROOM;i++) {
    sf::RectangleShape shape(sf::Vector2f(40,40));
    shape.setPosition(x+40*((i-START)%mid),y+40*floor((i-START)/mid));
    shape.setFillColor(sf::Color(0,0,0,0));
    shape.setOutlineColor(sf::Color(0,0,0));
    shape.setOutlineThickness(1);
    borders.push_back(shape);
  }
}

void ExtraBoard::reset(You* you) {
  extras.clear();
  int mid = floor((FINALROOM+START)*1.0/2);
  for (int i=START;i<FINALROOM;i++) {
    if (!you->hasExtra(static_cast<L_CODE>(i)))
      continue;
    float rad = 25/2.0;
    sf::CircleShape shape(rad);
    shape.setPosition(x+20-rad+40*((i-START)%mid),y+20-rad+40*floor((i-START)/mid));
    shape.setFillColor(sf::Color(255,0,255));
    extras.push_back(shape);
  }
}

void ExtraBoard::render(sf::RenderWindow& window) {
  for (size_t i=0;i<borders.size();i++)
    window.draw(borders[i]);
  for (size_t i=0;i<extras.size();i++)
    window.draw(extras[i]);
  
}
