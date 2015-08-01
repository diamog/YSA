#include "achievements.h"

Achievement::Achievement(A_CODE ach) : Actor(NULL,200,100,300,100){

  if (ach==SAVE_1) {
    name="You Saved!";
    snippet="The circle of regen+1000";
    desc="Hit that circle thing that flashes";
  }
  else if (ach==DIE_1) {
    name="The first of many";
    snippet="Get used to it";
    desc="Fall to the mighty hands of mortality";
  }
  else if (ach==DIE_10) {
    name="A few corpses";
    snippet="Is it hard yet?";
    desc="Leave ten friends behind";
  }
  shape.setFillColor(sf::Color(0,190,0));
  shape.setOutlineColor(sf::Color(50,50,50,150));
  shape.setOutlineThickness(20);
  alpha=255;
  tick=0;
  shape.setPosition(x,y);
  shape.setSize(sf::Vector2f(width,height));
  font.loadFromFile("Fonts/arial.ttf");
  name_text.setFont(font);
  name_text.setString(name);
  int size = 24;
  name_text.setCharacterSize(size);
  name_text.setOrigin(size*name.length()/4,0);
  name_text.setPosition(x+width/2,y+10);
  name_text.setColor(sf::Color(0,0,0));
  snip.setFont(font);
  snip.setString(snippet);
  int size2 = 15;
  snip.setCharacterSize(size2);
  snip.setPosition(x+15,y+50);
  snip.setColor(sf::Color(0,0,0));
}

void Achievement::render(sf::RenderWindow& window) {
  tick++;
  if (tick>60)
    alpha-=3;
  shape.setFillColor(sf::Color(0,190,0,alpha));
  shape.setOutlineColor(sf::Color(50,50,50,150*alpha/255));
  window.draw(shape);
  name_text.setColor(sf::Color(0,0,0,alpha));
  window.draw(name_text);
  snip.setColor(sf::Color(0,0,0,alpha));
  window.draw(snip);
}
