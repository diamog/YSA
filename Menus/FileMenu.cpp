#include "stdafx.h"
#include <iostream>
#include "FileMenu.h"
#include "../Extras/utilities.h"

FileMenu::FileMenu() {
  choice=0;
  font.loadFromFile("Fonts/arial.ttf");
  setupText(title,font,"Yellow Square\n   Adventure",82,sf::Color(255,255,0),
	    350,20,7);
  setupText(f1,font,"File 1",60,sf::Color(0,0,0),130,220);
  setupText(f2,font,"File 2",60,sf::Color(0,0,0),350,220);
  setupText(f3,font,"File 3",60,sf::Color(0,0,0),570,220);
  setupText(back,font,"Back",60,sf::Color(0,0,0),350,510);
  setRectPos(select,f1);
  select.setFillColor(sf::Color(0,0,0,0));
  select.setOutlineColor(sf::Color(255,255,0));
  select.setOutlineThickness(5);
  isLeave=false;
  isDown=isUp=isLeft=isRight=isEnter=false;
}
void FileMenu::setChoice() {
  
  choice%=6;
  if (choice==0)
    setRectPos(select,f1);
  else if (choice==1)
    setRectPos(select,f2);
  else if (choice==2)
    setRectPos(select,f3);
  else
    setRectPos(select,back);
}
void FileMenu::act() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    isLeave=false;
    if (isEnter)
      isLeave=true;
    isEnter=false;
  }
  else 
    isEnter=true;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    if (isUp) {
      choice+=3;
      setChoice();
    }
    isUp=false;
    
  }
  else
    isUp=true;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    if (isLeft&&choice<3) {
      choice--;
      if (choice<0)
	choice+=3;
      setChoice();
    }
    isLeft=false;
    
  }
  else
    isLeft=true;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    if (isRight&&choice<3) {
      choice++;
      if (choice>2)
	choice-=3;
      setChoice();
    }
    isRight=false;
    
  }
  else
    isRight=true;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    if (isDown) {
      choice+=3;
      setChoice();
    }
    isDown=false;
    
  }
  else
    isDown=true;

}

void FileMenu::render(sf::RenderWindow& window) {
  window.draw(title);
  window.draw(select);
  window.draw(f1);
  window.draw(f2);
  window.draw(f3);
  window.draw(back);
}

bool FileMenu::isChangeMenu(int& menu) {
  if (isLeave) {
    if (choice==0)
      menu=-2;
    else if (choice==1)
      menu=-3;
    else if (choice==2)
      menu=-4;
    else
      menu=0;
    return true;
  }
  return false;
}
