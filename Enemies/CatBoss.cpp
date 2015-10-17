#include "stdafx.h"
#include "CatBoss.h"
#include "CatRocket.h"
#include "CatBullet.h"
#include "CatLaser.h"
#include "../Extras/utilities.h"
#include <cmath>
#include "../Level.h"

CatBoss::CatBoss() : Actor(),Enemy() {
}

CatBoss::CatBoss(Level* l, You* yo) : 
  Actor(l,250,-150,175,150), Enemy(l,x,y,width,height,yo,0) {
  hp = (std::min(you->getDifficulty(),HARD)+1)*3;
  maxhp=hp;
  col=200;
  cat_head.setSize(sf::Vector2f(80,50));
  cat_head.setPosition(getX1()+width/2-40,getY1());
  cat_head.setFillColor(sf::Color(0,0,col));

  shape.setRadius(1);
  shape.setScale(width/2,100);
  shape.setFillColor(sf::Color(col,col,col));
  shape.setPosition(getX1()+width/2,getY1()+40);
  shape.setBounds(0,180);

  float width_s=15;
  spawner.setRadius(width_s);
  spawner.setOrigin(width_s,width_s);
  spawner.setFillColor(sf::Color(col,col,0));
  part=0;
  ticks=0;
  ticks2=0;
  isHit=false;
  dir = 1;
  
  numRockets=7;
  if (you->getDifficulty()==HARD)
    numRockets=10;
}

std::vector<Circle> CatBoss::getCircles() {
  std::vector<Circle> circs;
  return circs;
}
void CatBoss::act() {
  for (unsigned int i=0;i<bullets.size();i++) {
    bullets[i]->act();
    if (bullets[i]->isGone()) {
      bullets.erase(bullets.begin()+i);
      i--;
    }
  }
  for (unsigned int i=0;i<plats.size();i++) {
    plats[i]->act();
  }
  if (you->getDead()) return;
  if (part==0) {
    y+=2;
    if (y>150)
      part=6;
  }
  if (part==1) {
    ticks++;
    if (ticks>40) {
      ticks=0;
      bullets.push_back(new CatBullet(level,spawner.getPosition().x,
				      spawner.getPosition().y,
				      spawner.getRadius(),you,&plats));
    }
  }
  else if (part==2) {

    ticks++;
    col--;
    if (ticks>=100) {
      ticks=0;
      part=3;
      plats.clear();
    }
  }
  else if (part==3) {
    plats.clear();
    y+=3;
    if (y>350) {
      part=4;
      skip = getRandInt(-numRockets,numRockets);
    }
  }
  else if (part==4) {
    ticks++;
    plats.clear();
    if (int(ticks)%60==0) {
      for (int i=-numRockets;i<=numRockets+1;i++) {
	if (skip!=i)
	  bullets.push_back(new CatRocket(level,spawner.getPosition().x,spawner.getPosition().y,i,numRockets,you));
      }
      int min = std::max(-4,-(skip+numRockets));
      int max = std::min(4,-(skip-numRockets));
      skip+=getRandInt(min,max);
    }
    if (ticks>60*6+40) 
      part=5;
  }
  else if (part==5) {
    if (col<200)
      col+=3;
    y-=3;
    if (y<=150) {
      part=1;
    }
  }
  else if (part==6) {
    ticks++;
    if (ticks>=100) {
      ticks=0;
      part=7;
      bullets.clear();
      plats.clear();
      bullets.push_back(new CatLaser(level,spawner.getPosition().x,
				     spawner.getPosition().y,you,this));
    }
  }
  else if (part==7) {
    x+=dir*4;
    if (getX2()>700)
      dir=-1;
    if (getX1()<0)
      dir=1;
    ticks++;
    if (ticks>50) {
      ticks=0;
      bullets.push_back(new CatBullet(level,spawner.getPosition().x,
				      spawner.getPosition().y,
				      spawner.getRadius(),you,NULL));
    }
    if (isHit) {
      ticks2++;
      col = 200+int(ticks2)%2;
      if (ticks2>=100) {
	ticks2=0;
	isHit=false;
      }
    }
  }
  Actor temp(level,cat_head.getPosition().x,cat_head.getPosition().y,
	     cat_head.getSize().x,cat_head.getSize().y);
  if (part==1&&isRectangularHit(you,&temp)) {
    int dir = getApproachDirection(you,&temp);
    if (dir==2) {
      hp--;
      you->hitCat();
      if (hp==maxhp*2/3) {
	part=6;
      }
      else
	part=2;
      ticks=0;
    }
    else
      you->die();
  }
}
void CatBoss::hit() {
  Enemy::hit();
  isHit=true;
  if (hp<=maxhp/3) {
    part=8;
    bullets.clear();
    std::cout<<hp<<"\n";
  }
}
#ifndef COMPILE_NO_SF
void CatBoss::render(sf::RenderWindow& window) {
  shape.setFillColor(sf::Color(col,col,col,255*(col%3!=0)));
  shape.setPosition(getX1()+width/2,getY1()+50);
  shape.render(window);
  cat_head.setFillColor(sf::Color(0,0,col,255*(col%3!=0)));
  cat_head.setPosition(getX1()+width/2-40,getY1());
  window.draw(cat_head);
  spawner.setFillColor(sf::Color(col,col,0,255*(col%3!=0)));
  spawner.setPosition(getX1()+width/2,getY2()-spawner.getRadius()-10);
  window.draw(spawner);
  for (unsigned int i=0;i<bullets.size();i++) {
    bullets[i]->render(window);
  }
  for (unsigned int i=0;i<plats.size();i++) {
    plats[i]->render(window);
  }

}
#endif
