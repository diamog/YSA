#include "stdafx.h"
#include "Follower.h"

Follower::Follower() : Enemy(), Actor() {
  hp = 0;
}

Follower::Follower(Level* l, float x_,float y_, You* yo,int num,
		   std::vector<Actor*>* actors) : Enemy(l,x_,y_,20,20,yo,3), Actor(l,x_,y_,20,20) {
  level_actors = actors;
  alpha=0;
  num_left=num;
}

void Follower::act() {
  pos.push_back(std::make_pair(you->getX1(),you->getY1()));
  if (alpha<250) {
    alpha+=1;
  }
  else if (alpha>=250&&alpha<255) {
    alpha=255;
    if (num_left>0) {
      level_actors->push_back(new Follower(level,x,y,you,
					   num_left-1,level_actors));
    }
  }
  else {
    Enemy::act();
    x = (*(pos.begin())).first;
    y = (*(pos.begin())).second;
    pos.pop_front();
  }
  
}

#ifndef COMPILE_NO_SF
void render(sf::RenderWindow& window) {

}
#endif
