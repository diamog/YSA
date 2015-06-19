#include "stdafx.h"
#include "Enemy.h"
#include "utilities.h"

Enemy::Enemy() : Mover(), Death() {
  hp = 0;
}

Enemy::Enemy(Level* l, float x_,float y_,float w,float h, You* yo, int health) : Mover(l,x_,y_,w,h), Death(l,x_,y_,w,h,yo) {
  hp=health;
}

void Enemy::hit() {
  hp--;
}

#ifndef COMPILE_NO_SF

void Enemy::act(sf::Event& event) {
  Mover::act(event);
  Death::act(event);
  //Check if hit by you's bullets
  for (unsigned int i=0;i<you->getBullets().size();i++)
    if (isRectangularHit(this,you->getBullets()[i])) 
      if (you->getBullets()[i]->getType()=="you") {
				hit();
				you->removeBullet(i);
				i--;
      }
  
}
#endif
