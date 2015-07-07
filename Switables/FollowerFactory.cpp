#include "stdafx.h"
#include "../Enemies/Follower.h"
#include "FollowerFactory.h"
#include "../Extras/utilities.h"

FollowerFactory::FollowerFactory() : Switch(){
  count=0;
  isOn=false;
}

FollowerFactory::FollowerFactory(Level* l, float x_, float y_, float w, float h,You* yo,int c,
				 std::vector<Actor*>* a) : Switch(l,x_,y_,w,h,yo) {
  eve=FACTORY;
  count = c;
  isOn=true;
  actors=a;
}

void FollowerFactory::activate() {
  if (isOn) 
    actors->push_back(new Follower(level,you->getX1(),you->getY1(),you,count-1,actors));
  isOn=false;
}
