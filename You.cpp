#include "stdafx.h"
#include "You.h"
#include <cmath>
#include <fstream>
You::You() : Actor(),Mover() {
  isJump=0;
  platx1=platx2=0;
  alpha=255;
  isPaused=isMessagePaused=isControlPaused=false;
  isColor=isCloud=isPump=isCat=isFire=isColor2=false;
  vx =0;deaths=0;
  hasEnterSplit=false;
}

You::You(float x_, float y_, float w, float h, bool* isD) :  
  Actor(NULL,x_,y_,w,h), Mover(NULL,x_,y_,w,h) {
  hasEnterSplit=false;
  deaths=0;
  savepoint = GAME_START;
  isDead = isD;
  alpha=255;
  isPaused=isMessagePaused=isControlPaused=false;
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
  downLimit = 2;
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
  float rate=1;
  if (fabs(shape.getRotation())<1)
    shape.setRotation(0);
  if (isJump>0&&shape.getRotation()!=0) {
    if (shape.getRotation()<0)
      shape.setRotation(shape.getRotation()+rate);
    else if (shape.getRotation()>180)
      shape.setRotation(shape.getRotation()+rate);
    else
      shape.setRotation(shape.getRotation()-rate);
  }
#ifndef COMPILE_NO_SF
  if (!isControlPaused) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      if (isJump==0) {
	platx1=platx2=0;
	float angle = shape.getRotation()*3.1415926535/180;
	
	dy=-.95*frame_diff*cos(angle);
	vx=2*.95*frame_diff*sin(angle);
	isJump=1;
      }
      else if (isJump==2) {
	if (dy>0)
	  dy=0;
	dy-=.65f*frame_diff;
	isJump=3;
	if (isKickLeft) {
	  vx=-.6*frame_diff;
	  dy=-.8f*frame_diff;
	  isJump=1;
	}
	if (isKickRight) {
	  vx=.6*frame_diff;
	  dy=-.8f*frame_diff;
	  isJump=1;
	}
      }
      else if (isJump==3) {
	if (isKickLeft) {
	  vx=-.6*frame_diff;
	  dy=-.8f*frame_diff;
	  isJump=1;
	}
	if (isKickRight) {
	  vx=.6*frame_diff;
	  dy=-.8f*frame_diff;
	  isJump=1;
	}
      }
    }
    else {
      if (isJump==1)
	isJump=2;
    
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      platx1=platx2=0;
      if (downLimit==2) {
	if (dy<0)
	  dy=0;
	dy+=.5*frame_diff;
      
      }
      if (isJump==0)
	isJump=1;
      downLimit=4;
    }
    else 
      downLimit=2;
  }
#endif
  float temp_dx=0;
#ifndef COMPILE_NO_SF
  if (!isControlPaused) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { 
      if (vx>0)
	vx-=.005*frame_diff;
      else {
	float angle = -shape.getRotation()*3.14/180;
	while (angle<-3.14/2)
	  angle+=2*3.14;
	if (isJump!=0)
	  angle=0;
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
	if (isJump!=0)
	  angle=0;
	while (angle<-3.14/2)
	  angle+=2*3.14;
	temp_dx=dx*cos(angle);
	if (angle>0)
	  y=base_y-sin(angle)*(getX1()-platx1)-height;
	else if (angle<0)
	  y=base_y-sin(angle)*(getX1()-platx2)-height;
  
      }
    }
  }
#endif
  if (fabs(vx)<.005*frame_diff*frame_diff)
    vx=0;
  x+=temp_dx+vx;
  if (fabs(vx)>0)
    vx-=(vx/fabs(vx))*.005*frame_diff;
  if ((getX1()>=platx2 || getX2()<=platx1)&&platx1!=platx2) {
    isJump=2;
    platx1=platx2=0;
    shape.setRotation(0);
  }
  y+=dy;
  if (isJump!=0)
    dy+=grav/(1+3*isKickLeft||isKickRight);
  if (dy>downLimit*frame_diff)
    dy=downLimit*frame_diff;
  isKickLeft=isKickRight=false;
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
  isKickRight=isKick;
  vx=0;
}

void You::hitRightWall(float x_,bool isKick) {
  x = x_-width;
  isKickLeft=isKick;
  vx=0;
}

void You::save(S_CODE s) {
  savepoint = s;
  std::set<L_CODE>::iterator itr;
  for (itr=temp_extras.begin();itr!=temp_extras.end();itr++) 
    extras.insert(*itr);
  temp_extras.clear();
  std::ofstream out_str(".8e91q02a38x74f29d302s");
  save(out_str);
}

void You::die() {
  deaths++;
  platx1=platx2;
  *isDead = true;
  //begin death animation
}

void You::reload() {
  shape.setRotation(0);
  vx=0;
  alpha=261;
  isJump=1;
  dy=0;
  platx1=platx2=0;
  for (unsigned int i=0;i<bullets.size();i++)
    delete bullets[i];
  bullets.clear();
  temp_extras.clear();
}

std::vector<Line> You::getLines() {
  std::vector<Line> lines;
  lines.push_back(Line(getX1(),getX2(),getY1(),getY1()));
  lines.push_back(Line(getX1(),getX2(),getY2(),getY2()));
  lines.push_back(Line(getX1(),getX1(),getY1(),getY2()));
  lines.push_back(Line(getX2(),getX2(),getY1(),getY2()));
  return lines;
}

void You::load(std::istream& in_str) {
  int val=0;
  in_str>>val;
  savepoint=static_cast<S_CODE>(val);
  
  int num;in_str>>num;
  for (int i=0;i<num;i++) {
    int l;in_str>>l;
    extras.insert(static_cast<L_CODE>(l));
  }

  in_str>>num;
  for (int i=0;i<num;i++) {
    int h;in_str>>h;
    hints.insert(h);
  }
  
  in_str>>isColor;
  in_str>>isCloud;
  in_str>>isPump;
  in_str>>isCat;
  in_str>>isFire;
  in_str>>isColor2;
    
  in_str>>deaths;

  in_str>>hasEnterSplit;
}
void You::save(std::ostream& out_str) {
  
  //Save current savepoint
  out_str<<savepoint<<"\n\n";

  //Save all extras
  out_str<<extras.size()<<"\n";
  std::set<L_CODE>::iterator itr;
  for (itr=extras.begin();itr!=extras.end();itr++)
    out_str<<*itr<<" ";
  out_str<<"\n\n";
  //Save all hints
  out_str<<hints.size()<<"\n";
  std::set<int>::iterator itr2;
  for (itr2=hints.begin();itr2!=hints.end();itr2++)
    out_str<<*itr2<<" ";
  out_str<<"\n\n";
  
  //Save boss completition
  out_str<<isColor<<" "<<isCloud<<" "<<isPump<<" "<<isCat<<" "<<isFire<<" "<<isColor2<<"\n\n";

  //Save death count
  out_str<<deaths<<"\n";

  //Entrances
  out_str<<hasEnterSplit<<"\n";
}

void You::controlPause() {
  isControlPaused=!isControlPaused;
  if (isJump==0)
    isJump=1;
}

