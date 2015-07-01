#include "stdafx.h"
#include "Follower.h"

Follower::Follower() : Actor(),Enemy() {
  hp = 0;
}

Follower::Follower(Level* l, float x_,float y_, You* yo,int num,
		   std::vector<Actor*>* actors,
		   std::list<std::pair<float,float> > start_pos,
		   std::list<float> angs) :  
  Actor(l,x_,y_,20,20),Enemy(l,x_,y_,20,20,yo,3) {
  angles=angs;
  pos=start_pos;
  level_actors = actors;
  alpha=0;
  num_left=num;
#ifndef COMPILE_NO_SF
  shape.setSize(sf::Vector2f(width,height));
  shape.setFillColor(sf::Color(180,180,0,0));
#endif
}

void Follower::act() {
  pos.push_back(std::make_pair(you->getX1(),you->getY1()));
  angles.push_back(you->getAngle());
  if (alpha<250) {
    alpha+=1*frame_diff;
  }
  else if (alpha>=250&&alpha<255) {
    alpha=255;
    if (num_left>0) {
      level_actors->push_back(new Follower(level,x,y,you,
					   num_left-1,level_actors,pos));
    }
  }
  else {
    Enemy::act();
    x = (*(pos.begin())).first;
    y = (*(pos.begin())).second;
    pos.pop_front();
#ifndef COMPILE_NO_SF
    shape.setRotation(*(angles.begin()));
#endif
    angles.pop_front();
  }
  
}

#ifndef COMPILE_NO_SF
void Follower::render(sf::RenderWindow& window) {
  shape.setPosition(x,y);
  shape.setFillColor(sf::Color(180,180,0,alpha));
  window.draw(shape);
}
#endif
