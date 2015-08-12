#include "stdafx.h"
#include <iostream>
#include "PauseMenu.h"
#include "../Extras/utilities.h"

PauseMenu::PauseMenu() {
  choice=0;
  font= getFont("Arial");
  setupText(cont,font,"Continue",60,sf::Color(255,255,0),350,40);
  setupText(options,font,"Options",60,sf::Color(230,230,230),350,120);
  setupText(achieves,font,"Achievements",60,sf::Color(230,230,230),350,200);
  setupText(quit,font,"Quit",60,sf::Color(255,255,0),350,500);
  setRectPos(select,cont);
  background.setPosition(0,0);
  background.setSize(sf::Vector2f(700,600));
  background.setFillColor(sf::Color(0,0,0,180));
  select.setFillColor(sf::Color(0,0,0,0));
  select.setOutlineColor(sf::Color(255,255,0));
  select.setOutlineThickness(5);
  isLeave=false;
  isDown=isUp=isEnter=false;
} 
void PauseMenu::setChoice() {
  choice+=4;
  choice%=4;
  if (choice==0)
    setRectPos(select,cont);
  else if (choice==1)
    setRectPos(select,options);
  else if (choice==2)
    setRectPos(select,achieves);
  else 
    setRectPos(select,quit);
}
void PauseMenu::act() {
  isLeave=false;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
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

void PauseMenu::render(sf::RenderWindow& window) {
  window.draw(background);
  window.draw(select);
  window.draw(cont);
  window.draw(quit);
  window.draw(options);
  window.draw(achieves);
}

bool PauseMenu::isChangeMenu(int& menu) {
  if (isLeave) {
    if (choice==0) {
      menu=-1;
      you->pause();
    }
    else if (choice==3) {
      menu=0;
      you->pause();
    }
    else
      return false;
    return true;
  }
  return false;
}
