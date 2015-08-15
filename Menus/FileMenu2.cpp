#include "stdafx.h"
#include <iostream>
#include "FileMenu2.h"
#include "../Extras/utilities.h"
#include "stdio.h"
#include "../Codes.h"

FileMenu2::FileMenu2() : board(40,600-125-90) {
  choice=0;
  font = getFont("Arial");
  setupText(title,font,"Yellow Square\n   Adventure",82,
	    sf::Color(255,255,0),350,20,7);
  setupText(file,font,"File",50,sf::Color(0,0,0),30,205,0);
  setupText(back,font,"Back",50,sf::Color(255,255,0),350,600-60);
  setupRect(border,20,260,680,600-70,sf::Color(0,0,0,0),sf::Color(0,0,0),5);
  setupRect(btop,20,200,file.findCharacterPos(4).x+10,600-70,
	    sf::Color(100,75,50),sf::Color(0,0,0),5);
  setupRect(b,20,260,680,600-70,sf::Color(100,75,50),sf::Color(0,0,0,0),0);
  setupText(new_game,font,"New Game",40,sf::Color(160,160,160),
	    40,600-125,0);
  setupText(cont,font,"Continue",40,sf::Color(255,255,0),
	    new_game.findCharacterPos(9).x+50,600-125,0);
  setupText(erase,font,"Erase",40,sf::Color(255,255,0),
	    cont.findCharacterPos(8).x+50,600-125,0);
  setRectPos(select,cont);
  select.setFillColor(sf::Color(0,0,0,0));
  select.setOutlineColor(sf::Color(255,255,0));
  select.setOutlineThickness(5);
  isLeave=false;
  isDown=isUp=isLeft=isRight=isEnter=false;
  you_ = NULL;
}
void FileMenu2::setYou(You* you) {
  board.reset(you);
  choice=0;
  you_ = you;
  if (you->getSave()==GAME_START) {
    new_game.setColor(sf::Color(255,255,0));
  }
  else {
    choice=1;
    std::string diff_text;
    if (you->getDifficulty()==EASY)
      diff_text="Easy";
    else if (you->getDifficulty()==MEDIUM)
      diff_text="Normal";
    else if (you->getDifficulty()==HARD)
      diff_text="Hard";
    else
      diff_text="Impossible";
    setupText(diff,font,diff_text,40,sf::Color(0,0,0),50,265,0);
    char deaths[15];
    sprintf(deaths,"Deaths: %d",you->getDeaths());
    setupText(death,font,std::string(deaths),30,sf::Color(0,0,0),
	      50,315,0);
    new_game.setColor(sf::Color(160,160,160));
    
  }
  setChoice();
}
void FileMenu2::setChoice() {
  
  choice%=6;
  if (choice==0)
    setRectPos(select,new_game);
  else if (choice==1)
    setRectPos(select,cont);
  else if (choice==2)
    setRectPos(select,erase);
  else
    setRectPos(select,back);
}
void FileMenu2::act() {
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
    if (isLeft&&choice<3&&you_->getSave()!=GAME_START) {
      if (choice==1)
	choice=2;
      else
	choice=1;
      if (choice<0)
	choice+=3;
      setChoice();
    }
    isLeft=false;
    
  }
  else
    isLeft=true;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    if (isRight&&choice<3&&you_->getSave()!=GAME_START) {
      if (choice==1)
	choice=2;
      else
	choice=1;
      
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

void FileMenu2::render(sf::RenderWindow& window) {
  window.draw(title);
  window.draw(border);
  window.draw(btop);
  window.draw(b);
  window.draw(file);
  
  if (you_->getSave()!=GAME_START) {
    window.draw(diff);
    window.draw(death);
    window.draw(cont);
    window.draw(erase);
    board.render(window);
  }
  else
    window.draw(new_game);
  window.draw(back);
  window.draw(select);
}

bool FileMenu2::isChangeMenu(int& menu) {
  if (isLeave) {
    if (choice==0&&you_->getSave()==GAME_START) {
      menu=-1;
    }
    else if (choice==1)
      menu=-1;
    else if (choice==2) {
      you_->reset();
      setYou(you_);
      //reset you stay on this menu
      return false;
    }
    else if (choice>=3)
      menu=1;
    return true;
  }
  return false;
}
