#include "stdafx.h"
#include "You.h"

You::You() : Mover() {
  isJump=0;
  platx1=platx2=0;
  alpha=255;
  isPaused=isMessagePaused=false;
}

You::You(float x_, float y_, float w, float h, bool* isD) : Mover(NULL,x_,y_,w,h), Actor(NULL,x_,y_,w,h) {
  savepoint = GAME_START;
  isDead = isD;
  alpha=255;
  isPaused=isMessagePaused=false;
#ifndef COMPILE_NO_SF
  shape.setSize(sf::Vector2f(width,height));
  shape.setFillColor(sf::Color(255,255,0));

  font.loadFromFile("Fonts/arial.ttf");
  you_died.setFont(font);
  you_died.setString("You Died");
  you_died.setCharacterSize(120);
  you_died.setColor(sf::Color(255,200,0,0));
  you_died.setPosition(120,100);
  text_restart.setFont(font);
  text_restart.setString("Press the r key to recolor yourself");
  text_restart.setCharacterSize(18);
  text_restart.setColor(sf::Color(255,200,0,0));
  text_restart.setPosition(230,220);
#endif
  isJump = 2;
  dx = .7f;
  dy=0;
  downLimit = 1;
  grav = 0.005f;
  platx1=platx2=0;

}

You::~You() {
  for (unsigned int i=0;i<bullets.size();i++)
    delete bullets[i];
  bullets.clear();
}

void You::act() {
	for (unsigned int i=0;i<bullets.size();i++)
		bullets[i]->act();
  Mover::act();
#ifndef COMPILE_NO_SF
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    if (isJump==0) {
      platx1=platx2=0;
      dy=-.95;
      isJump=1;
    }
    else if (isJump==2) {
      if (dy>0)
	dy=0;
      dy-=.65f;
      isJump=3;
    }
  }
  else {
    if (isJump==1)
      isJump=2;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		platx1=platx2=0;
    if (downLimit==1) {
      if (dy<0)
	dy=0;
      dy+=.5;
      
    }
    if (isJump==0)
	isJump=1;
    downLimit=2;
  }
  else 
    downLimit=1;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
    x-=dx;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    x+=dx;
#endif
  if ((x>platx2 || x+width<platx1)&&platx1!=platx2) {
    isJump=2;
    platx1=platx2=0;
  }
  y+=dy;
  if (isJump!=0)
    dy+=grav;
  if (dy>downLimit)
    dy=downLimit;	
}

#ifndef COMPILE_NO_SF
void You::render(sf::RenderWindow& window) {
	for (unsigned int i=0;i<bullets.size();i++)
		bullets[i]->render(window);
  shape.setPosition(x,y);
  if ((*isDead&&alpha>0)||alpha==256) {
    alpha--;
    shape.setFillColor(sf::Color(255,255,0,alpha));
    you_died.setColor(sf::Color(255,255,0,255-alpha));
    text_restart.setColor(sf::Color(255,255,0,255-alpha));
  }
  window.draw(shape);
	if (alpha<255) {
		window.draw(you_died);
		window.draw(text_restart);
	}
	
}
#endif
void You::print() {
	std::cout<<getLastY1()<<" "<<getLastY2()<<" "<<getY1()<<" "<<getY2()<<std::endl;
}
void You::setPosition(float x_, float y_) {
  x=x_;
  y=y_;
  lastx=x_;
  lasty=y_;
	platx1=platx2=0;
}
void You::land(float y_,float x1, float x2) {
  y = y_-height;
  dy=0;
  isJump=0;
  platx1 = x1;
  platx2 = x2;
}

void You::ceiling(float y_) {
  y = y_;
  if (dy<0)
    dy = 0;
}

void You::hitLeftWall(float x_,float y1, float y2,bool isKick) {
  x = x_;
}

void You::hitRightWall(float x_,float y1, float y2,bool isKick) {
  x = x_-width;
}

void You::save(S_CODE s) {
  savepoint = s;
}

void You::die() {
  deaths++;
  platx1=platx2;
  *isDead = true;
  //begin death animation
}

void You::reload() {
	alpha=256;
	isJump=1;
	dy=0;
	platx1=platx2=0;
	for (unsigned int i=0;i<bullets.size();i++)
		delete bullets[i];
  bullets.clear();
}
