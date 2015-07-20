#include "stdafx.h"
#include "WallVine.h"
#include "utilities.h"
WallVine::WallVine() : Actor(),Vine() {
}

WallVine::WallVine(Level* l,int s,You* yo) 
  : Actor(l,0,600,40,600), Vine(l,0,yo) {
  side=s;
  if (side==0) {
    angle=0;
    x = -width+1;
  }
  if (side==1) {
    angle=-3.141592;
    x=700-1;
  }
  vel=5;
  ticks=0;
  shape2.setSize(sf::Vector2f(width,height));
}

void WallVine::act() {
  ticks++;
  if (ticks>30) 
    PBullet::act();
  y=600;
  if (side==0&&x>=0) {
    vel=0;
  }
  if (side==1&&x<=700-width)
    vel=0;
  if (ticks>240) {
    vel=5;
    angle-=3.1415926535;
    if (side==0)
      x-=5;
    else
      x+=5;
    
    ticks=60;
  }
}

void WallVine::render(sf::RenderWindow& window) {
  Vine::render(window);
}
