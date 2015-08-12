#include "stdafx.h"
#include <iostream>
#include "FileMenu.h"
#include "../Extras/utilities.h"
#include "stdio.h"
#include "../Codes.h"

void FileMenu::setupFileMenu(int index,float x1, You* you) {
  char f_name[9];
  sprintf(f_name,"File %d",index+1);
  setupText(f[index],font,std::string(f_name),60,sf::Color(255,255,0),x1+100,220);
  setupRect(b[index],x1,210,x1+200,490,sf::Color(100,75,50),sf::Color(0,0,0),5);
  if (you->getSave()==GAME_START) {
    diff[index].setColor(sf::Color(0,0,0,0));
    death[index].setColor(sf::Color(0,0,0,0));
  }
  else {
    setupText(diff[index],font,"Normal",40,sf::Color(0,0,0),x1+100,360);
    char deaths[15];
    sprintf(deaths,"Deaths: %d",you->getDeaths());
    setupText(death[index],font,std::string(deaths),30,sf::Color(0,0,0),x1+100,440,6);
  }

}

FileMenu::FileMenu(You* you1, You* you2, You* you3) {
  choice=0;
  font.loadFromFile("Fonts/arial.ttf");
  setupText(title,font,"Yellow Square\n   Adventure",82,sf::Color(255,255,0),
	    350,20,7);
  restart(you1,you2,you3);
  setupText(back,font,"Back",60,sf::Color(255,255,0),350,510);
  setRectPos(select,f[0]);
  select.setFillColor(sf::Color(0,0,0,0));
  select.setOutlineColor(sf::Color(255,255,0));
  select.setOutlineThickness(5);
  isLeave=false;
  isDown=isUp=isLeft=isRight=isEnter=false;
}

void FileMenu::restart(You* you1, You* you2, You* you3) {
  setupFileMenu(0,30,you1);
  setupFileMenu(1,250,you2);
  setupFileMenu(2,470,you3);

}
void FileMenu::setChoice() {
  
  choice%=6;
  if (choice<3)
    setRectPos(select,f[choice]);
  else
    setRectPos(select,back);
}
void FileMenu::act() {
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

  for (int i=0;i<3;i++) {
    window.draw(b[i]);
    window.draw(f[i]);
    window.draw(diff[i]);
    window.draw(death[i]);
  }
  window.draw(select);
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
