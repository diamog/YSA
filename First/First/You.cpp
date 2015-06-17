#ifndef COMPILE_NO_VB
#include "stdafx.h"
#endif
#include "You.h"

You::You() : Mover() {
  isJump=0;
  sWidth = 0;
  sHeight = 0;
  platx1=platx2=0;
}

You::You(float x_, float y_, float w, float h, int screenW, int screenH) : Mover(NULL,x_,y_,w,h) {
  sWidth = screenW;
  sHeight = screenH;
#ifndef COMPILE_NO_SF
  shape.setSize(sf::Vector2f(width,height));
  shape.setFillColor(sf::Color(255,255,0));
#endif
  isJump = 2;
  dx = .7f;
  dy=0;
  downLimit = 1;
  grav = 0.005f;
  platx1=platx2=0;
}

#ifndef COMPILE_NO_SF
void You::act(sf::Event& event) {
  Mover::act(event);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    if (isJump==0) {
      platx1=platx2=0;
      dy=-1;
      isJump=1;
    }
    else if (isJump==2) {
      if (dy>0)
	dy=0;
      dy-=.7f;
      isJump=3;
    }
  }
  else {
    if (isJump==1)
      isJump=2;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    if (downLimit==1) {
      if (dy<0)
	dy=0;
      dy+=.5;
    }
    downLimit=2;
  }
  else 
    downLimit=1;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
    x-=dx;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    x+=dx;

  if ((x>platx2 || x+width<platx1)&&platx1!=platx2) {
    isJump=2;
    platx1=platx2=0;
  }
  y+=dy;
  if (isJump!=0)
    dy+=grav;
  if (y+height>sHeight) {
    y = sHeight-height;
    isJump=0;
  }
  if (dy>downLimit)
    dy=downLimit;	
}

void You::render(sf::RenderWindow& window) {
  shape.setPosition(x,y);
  window.draw(shape);
}
#endif

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

void You::die() {
  deaths++;
  dy=0;
  isJump=1;
  platx1=platx2;
  *isDead = true;
  //begin death animation
}
