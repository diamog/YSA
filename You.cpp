#include "stdafx.h"
#include "You.h"
#include <cmath>

You::You() : Actor(),Mover() {
  isJump=0;
  platx1=platx2=0;
  alpha=255;
  isPaused=isMessagePaused=false;
  isColor=isCloud=isPump=isCat=isFire=isColor2=false;
  vx =0;
}

You::You(float x_, float y_, float w, float h, bool* isD) :  
  Actor(NULL,x_,y_,w,h), Mover(NULL,x_,y_,w,h) {
  savepoint = GAME_START;
  isDead = isD;
  alpha=255;
  isPaused=isMessagePaused=false;
  isColor=isCloud=isPump=isCat=isFire=isColor2=false;
  //isColor=true;
  vx=0;
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
  dx = .7f*frame_diff;
  dy=0;
  downLimit = 1;
  grav = 0.005f*frame_diff*frame_diff;
  platx1=platx2=0;
  base_y=0;
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
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    if (isJump==0) {
      platx1=platx2=0;
      float angle = shape.getRotation()*3.1415926535/180;
      
	
      dy=-.95*frame_diff*cos(angle);
      vx=.95*frame_diff*sin(angle);
      isJump=1;
      shape.setRotation(0);
    }
    else if (isJump==2) {
      if (dy>0)
	dy=0;
      dy-=.65f*frame_diff;
      isJump=3;
    }
  }
  else {
    if (isJump==1)
      isJump=2;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
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
#endif
  float temp_dx=0;
#ifndef COMPILE_NO_SF
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { 
    if (vx>0)
      vx-=.005*frame_diff;
    else {
      float angle = -shape.getRotation()*3.14/180;
      temp_dx=-dx*cos(angle);
      if (angle>0)
	y=base_y-sin(angle)*(getX1()-platx1)-height;
      else if (angle<0)
	y=base_y-sin(angle)*(getX1()-platx2)-height;
  
    }
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    if (vx<0)
      vx+=.005*frame_diff;
    else {
      float angle = -shape.getRotation()*3.14/180;
      temp_dx=dx*cos(angle);
      if (angle>0)
	y=base_y-sin(angle)*(getX1()-platx1)-height;
      else if (angle<0)
	y=base_y-sin(angle)*(getX1()-platx2)-height;
  
    }
  }
#endif
  if (fabs(vx)<.005)
    vx=0;
  x+=temp_dx+vx;
  if (fabs(vx)>0)
    vx-=(vx/fabs(vx))*.005;
  if ((getX1()>=platx2 || getX2()<=platx1)&&platx1!=platx2) {
    isJump=2;
    platx1=platx2=0;
    shape.setRotation(0);
  }
  y+=dy;
  if (isJump!=0)
    dy+=grav;
  if (dy>downLimit*frame_diff)
    dy=downLimit*frame_diff;	
}

#ifndef COMPILE_NO_SF
void You::render(sf::RenderWindow& window) {
  for (unsigned int i=0;i<bullets.size();i++)
    bullets[i]->render(window);
  shape.setPosition(getX1(),getY1());
  if ((*isDead&&alpha>0)||alpha==261) {
    alpha-=6;
    shape.setFillColor(sf::Color(255,255,0,alpha));
    you_died.setColor(sf::Color(255,255,0,255-alpha));
    text_restart.setColor(sf::Color(255,255,0,255-alpha));
  }
  if (alpha<6)
    alpha=0;
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
void You::setPosition(float x_, float y_,bool keepLast) {
  x=x_;
  y=y_;
  if (!keepLast) {
    lastx=x_;
    lasty=y_;
  }
  platx1=platx2=0;
}
void You::land(float y_,float x1, float x2) {
  y = y_-height;
  dy=0;
  isJump=0;
  vx=0;
  platx1 = x1;
  platx2 = x2;
  shape.setRotation(0);
}

void You::landSlope(float y_,float x1,float x2,float angle) {
  platx1=x1;
  platx2=x2;
  dy=0;
  vx=0;
  isJump=0;
  base_y=y_;
  if (angle>0)
    y=y_-sin(angle)*(getX1()-x1)-height;
  else 
    y=y_-sin(angle)*(getX1()-x2)-height;
  shape.setRotation(-(angle*180/3.14));
}

void You::ceiling(float y_) {
  y = y_;
  if (dy<0)
    dy = 0;
}

void You::hitLeftWall(float x_,bool isKick) {
  x = x_;
}

void You::hitRightWall(float x_,bool isKick) {
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
  alpha=261;
  isJump=1;
  dy=0;
  platx1=platx2=0;
  for (unsigned int i=0;i<bullets.size();i++)
    delete bullets[i];
  bullets.clear();
}

std::vector<Line> You::getLines() {
  std::vector<Line> lines;
  lines.push_back(Line(getX1(),getX2(),getY1(),getY1()));
  lines.push_back(Line(getX1(),getX2(),getY2(),getY2()));
  lines.push_back(Line(getX1(),getX1(),getY1(),getY2()));
  lines.push_back(Line(getX2(),getX2(),getY1(),getY2()));
  return lines;
}
