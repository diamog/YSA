#include "stdafx.h"
#include "../Extras/utilities.h"
#include "CloudBoss.h"
#include "../Level.h"
#include <cmath>

CloudBoss2::CloudBoss2() : Actor(),Enemy() {}

void makeCloud2(sf::CircleShape& shape) {
  shape.setFillColor(sf::Color(255,255,255));
  shape.setRadius(20);
}
CloudBoss2::CloudBoss2(Level* l, You* yo) 
  : Actor(l,750,400,80,60), Enemy(l,750,400,80,60,yo,7) {
  ticks=0;
  rate=1.5;
  max_ticks=150;
  nose.setSize(sf::Vector2f(10,10));
  nose.setFillColor(sf::Color(0,255,255));
  makeCloud2(top);
  makeCloud2(left);
  makeCloud2(right);
  part=0;
  hit_ticks=0;
  isHit=false;
  bullet_tick=0;
  wind_dir=1;
  wind_tick=0;
  storm_ticks=0;
  if (you->boss2Half()) {
    x=350;
    y=100;
    part=1;
  }
  eye= new RedSwitch(level,x+width/2-15,y+30,30,you,RED_1);

}

CloudBoss2::~CloudBoss2() {
  for (unsigned int i=0;i<bullets.size();i++)
    delete bullets[i];
  bullets.clear();
  for (unsigned int i=0;i<storms.size();i++)
    delete storms[i];
  storms.clear();
  if (part<5)
    delete eye;
}

std::vector<Circle> CloudBoss2::getCircles() {
  if (part==5)
    return std::vector<Circle>();
  std::vector<Circle> cs;
  cs.push_back(Circle(getX1()+width/2,getY1()+20,20));
  cs.push_back(Circle(getX1()+width/2-30,getY1()+40,20));
  cs.push_back(Circle(getX1()+width/2+30,getY1()+40,20));
  return cs;
}

void CloudBoss2::act() {
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
    if (part==1&&testCircles(this,storms[i])&&!isHit) {
      hp--;
      rate+=.1;
      isHit=true;
    }
    if (storms[i]->getDead()) {
      delete storms[i];
      storms.erase(storms.begin()+i);
      i--;
    }
  }
  if (part==5)
    return;
  if (part==0) {
    shiftX(-5);
    eye->shiftX(-5);
    double a = -3.0/845;
    double b = 840.0/169;
    double c = -209500.0/169;
    double oldy=y;
    float cx=x+width/2;
    y = a*cx*cx+b*cx+c;
    eye->shiftY(y-oldy);
    if (y<=25) {
      part=1;
    }
  }
  else if (part==1) {
    float cx,cy,yx,yy;
    getObjectCenter(you,yx,yy);
    getObjectCenter(this,cx,cy);
    float vel=1.2;
    shiftX((fabs(cx-yx)>5)*(yx-cx)/(fabs(cx-yx))*vel);
    shiftY((fabs(cy-yy)>5)*(yy-cy)/(fabs(yy-cy))*vel);
    eye->shiftX((fabs(cx-yx)>5)*(yx-cx)/(fabs(cx-yx))*vel);
    eye->shiftY((fabs(cy-yy)>5)*(yy-cy)/(fabs(yy-cy))*vel);
    if (hp<=0)
      part=2;
  }
  else if (part==2) {
    float targetx=350;
    float targety=140;
    float cx,cy;
    float vel=2.5;
    getObjectCenter(this,cx,cy);
    shiftX((fabs(cx-targetx)>5)*(targetx-cx)/(fabs(cx-targetx))*vel);
    shiftY((fabs(cy-targety)>5)*(targety-cy)/(fabs(targety-cy))*vel);
    eye->shiftX((fabs(cx-targetx)>5)*(targetx-cx)/(fabs(cx-targetx))*vel);
    eye->shiftY((fabs(cy-targety)>5)*(targety-cy)/(fabs(targety-cy))*vel);
    if (fabs(cx-targetx)+fabs(cy-targety)<=10)
      part=3;
  }
  else if (part==3){
    if (storm_ticks%(max_ticks/2)==0) {
      storms.push_back(new Storm(level,you->getX1()+you->getWidth()/2-60,40,you));
    }
    if (storm_ticks>30*30) 
      part=4;
    if (!you->getDead()) {
      storm_ticks++;
      bullet_tick++;
    }
  }
  else if (part==4){
    
    float cx,cy,yx,yy;
    getObjectCenter(you,yx,yy);
    getObjectCenter(this,cx,cy);
    float vel=1.2;
    shiftX((fabs(cx-yx)>5)*(yx-cx)/(fabs(cx-yx))*vel);
    shiftY((fabs(cy-yy)>5)*(yy-cy)/(fabs(yy-cy))*vel);
    eye->act();
  }
  if (isHit) {
    hit_ticks++;
    if (hit_ticks>80) {
      hit_ticks=0;
      isHit=false;
    }
  }
  if (you->getDead()) {
    return;
  }
  ticks+=rate;
  if (ticks>=max_ticks) {
    ticks=0;
    storms.push_back(new Storm(level,getRand(50,480+50),40,you));
  }
  if (testCircles(this,you)) {
    you->die();
  }
  if (hp<=5) {
    //make rain
    bullet_tick++;
    if (bullet_tick>25) { 
      bullets.push_back(new CBullet(level,getRand(50,650),-40,you,NULL));
      bullet_tick=0;
    }
  }
  if (hp<=3) {
    //make wind
    bullet_tick+=0.2;
    wind_tick++;
    if (wind_tick>450) {
      wind_tick=0;
      wind_dir*=-1;
    }
    you->shiftX(wind_dir*0.2);
    for (size_t i=0;i<bullets.size();i++) {
      bullets[i]->shiftX(.2*wind_dir);
    }
  }
}

#ifndef COMPILE_NO_SF
void CloudBoss2::render(sf::RenderWindow& window) {
  for (unsigned int i=0;i<bullets.size();i++)
    bullets[i]->render(window);
  for (unsigned int i=0;i<storms.size();i++)
    storms[i]->render(window);
  if (part!=5) eye->render(window);
  if (part!=5) alpha=255;
  else alpha-=3;
  if (hit_ticks%2)
    alpha=0;
  int col = 255-ticks*1.0/max_ticks*180;
  left.setFillColor(sf::Color(col,col,col,alpha));
  left.setPosition(getX1()+width/2-50,getY1()+20);
  window.draw(left);
  right.setFillColor(sf::Color(col,col,col,alpha));
  right.setPosition(getX1()+width/2+10,getY1()+20);
  window.draw(right);
  top.setFillColor(sf::Color(col,col,col,alpha));
  top.setPosition(getX1()+width/2-20,getY1());
  window.draw(top);
  nose.setFillColor(sf::Color(0,255,255,alpha));
  nose.setPosition(getX1()+width/2-5,getY1()+50);
  window.draw(nose);
}
#endif
