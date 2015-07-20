#include "stdafx.h"
#include "../Enemies/Follower.h"
#include "FollowerFactory.h"
#include "../Extras/utilities.h"
#include "../Level.h"
FollowerFactory::FollowerFactory() : Switch(){
  count=0;
  isOn=false;
}

FollowerFactory::FollowerFactory(Level* l, float x_, float y_, float w, float h,You* yo,int c,
				 std::vector<Actor*>* a) : Switch(l,x_,y_,w,h,yo) {
  eve=NOTHING;
  count = c;
  isOn=true;
  actors=a;
}

void FollowerFactory::activate() {
  if (isOn) 
    actors->push_back(new Follower(level,you->getX1()+level->getX(),you->getY1()+level->getY(),you,count-1,actors));
  isOn=false;
}
