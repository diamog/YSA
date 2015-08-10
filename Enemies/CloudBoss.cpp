#include "stdafx.h"
#include "../Extras/utilities.h"
#include "CloudBoss.h"
#include "../Level.h"
#include <cmath>

CloudBoss1::CloudBoss1() : Actor(),Enemy() {}

void makeCloud(sf::CircleShape& shape) {
  shape.setFillColor(sf::Color(255,255,255));
  shape.setRadius(20);
}
CloudBoss1::CloudBoss1(Level* l, You* yo,SmallEye* e) 
  : Actor(l,350,150,120,120), Enemy(l,350,150,120,120,yo,5) {
  ticks=0;
  angle=0;
  rate=1;
  max_ticks=150;
  dir=-1;
  diry=-1;
  eye= new RedSwitch(level,x+width/2-15,y+30,30,you,RED_1);
  nose.setSize(sf::Vector2f(10,10));
  nose.setFillColor(sf::Color(0,255,255));
  for (int i=0;i<3;i++) {
    clouds.push_back(new Cloud(level,x+i*40,y+40,you,e,&bullets));
  }
  makeCloud(top);
  makeCloud(left);
  makeCloud(right);
  base_y=y;
}

CloudBoss1::~CloudBoss1() {
  for (unsigned int i=0;i<bullets.size();i++)
    delete bullets[i];
  bullets.clear();
  
  for (unsigned int i=0;i<clouds.size();i++)
    delete clouds[i];
  clouds.clear();
  delete eye;
}

std::vector<Circle> CloudBoss1::getCircles() {
  std::vector<Circle> cs;
  cs.push_back(Circle(getX1()+width/2,getY1()+20,20));
  cs.push_back(Circle(getX1()+width/2-30,getY1()+40,20));
  cs.push_back(Circle(getX1()+width/2+30,getY1()+40,20));
  return cs;
}


void CloudBoss1::act() {
  for (unsigned int i=0;i<bullets.size();i++) {
    bullets[i]->act();
    if (bullets[i]->isGone()) {
      delete bullets[i];
      bullets.erase(bullets.begin()+i);
      i--;
    }
  }
  for (unsigned int i=0;i<storms.size();i++) {
    storms[i]->act();
    if (storms[i]->getDead()) {
      delete storms[i];
      storms.erase(storms.begin()+i);
      i--;
    }
  }
  float vel=4;
  float amp=50;
  x+=dir*vel;
  eye->shiftX(dir*vel);
    
  if (clouds.size()) {
    
    float pi=3.1415926535;
    angle+=pi/50*(2-clouds.size()/2);
    float yshift = (base_y+amp*sin(angle))-y;
    shiftY(yshift);
    for (unsigned int i=0;i<clouds.size();i++) {
      if (clouds[i]->getDead()) {
	clouds.erase(clouds.begin()+i);
	i--;
	rate+=.5;
	for (unsigned int j=0;j<clouds.size();j++)
	  clouds[j]->speedup();
      }
      else {
	clouds[i]->shiftX(dir*vel);
	clouds[i]->shiftY(yshift);
	if (!you->getDead())
	  clouds[i]->act();
      }
    }
    eye->shiftY(yshift);
    
  }
  else {
    shiftY(diry*vel);
    eye->shiftY(diry*vel);
    if (y<30)
      diry=1;
    else if (y>570-height/2)
      diry=-1;
  }
  eye->act();
  if (x<30)
    dir=1;
  else if (x>670-width)
    dir=-1;
  
  if (you->getDead()) {
    return;
  }
  if (testCircles(this,you)) {
    you->die();
  }
  ticks+=rate;
  if (ticks>=max_ticks) {
    ticks=0;
    storms.push_back(new Storm(level,you->getX1()+you->getWidth()/2-60,40,you));
  }
}

#ifndef COMPILE_NO_SF
void CloudBoss1::render(sf::RenderWindow& window) {
  // pumpkin.setPosition(getX1(),getY1());
  // pumpkin.setTexture(pumpkin1);
  // window.draw(pumpkin);
  for (unsigned int i=0;i<bullets.size();i++)
    bullets[i]->render(window);
  for (unsigned int i=0;i<storms.size();i++)
    storms[i]->render(window);
  eye->render(window);
  int col = 255-ticks*1.0/max_ticks*180;
  for (unsigned int i=0;i<clouds.size();i++)
    clouds[i]->render(window);
  left.setFillColor(sf::Color(col,col,col));
  left.setPosition(getX1()+width/2-50,getY1()+20);
  window.draw(left);
  right.setFillColor(sf::Color(col,col,col));
  right.setPosition(getX1()+width/2+10,getY1()+20);
  window.draw(right);
  top.setFillColor(sf::Color(col,col,col));
  top.setPosition(getX1()+width/2-20,getY1());
  window.draw(top);
  nose.setPosition(getX1()+width/2-5,getY1()+50);
  window.draw(nose);
}
#endif
