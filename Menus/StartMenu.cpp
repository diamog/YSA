#include "stdafx.h"
#include <iostream>
#include "StartMenu.h"
#include "../Extras/utilities.h"
StartMenu::StartMenu() {
  choice=0;
  font.loadFromFile("Fonts/arial.ttf");
  setupText(title,font,"Yellow Square\n   Adventure",82,sf::Color(255,255,0),
	    350,20,7);
  setupText(start,font,"Start",60,sf::Color(255,255,0),350,300);
  setupText(options,font,"Options",60,sf::Color(230,230,230),350,400);
  setupText(achieves,font,"Achievements",60,sf::Color(230,230,230),350,500);
  setRectPos(select,start);
  select.setFillColor(sf::Color(0,0,0,0));
  select.setOutlineColor(sf::Color(255,255,0));
  select.setOutlineThickness(5);
  isLeave=false;
  isDown=isUp=isEnter=false;
}
void StartMenu::setChoice() {
  choice+=3;
  choice%=3;
  if (choice==0)
    setRectPos(select,start);
  else if (choice==1)
    setRectPos(select,options);
  else
    setRectPos(select,achieves);
}
void StartMenu::act() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
    isLeave=false;
    if (isEnter)
      isLeave=true;
    isEnter=false;
  }
  else 
    isEnter=true;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    if (isUp) {
      choice--;
      setChoice();
    }
    isUp=false;
    
  }
  else
    isUp=true;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    if (isDown) {
      choice++;
      setChoice();
    }
    isDown=false;
    
  }
  else
    isDown=true;

}

void StartMenu::render(sf::RenderWindow& window) {
  window.draw(title);
  window.draw(select);
  window.draw(start);
  window.draw(options);
  window.draw(achieves);
}

bool StartMenu::isChangeMenu(int& menu) {
  if (isLeave) {
    if (choice==0)
      menu=1;
    else
      return false;
    return true;
  }
  return false;
}
