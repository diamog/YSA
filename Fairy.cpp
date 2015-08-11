#include "stdafx.h"
#include "Fairy.h"
#include "Level.h"
#include "Extras/utilities.h"
#include <cmath>

Fairy::Fairy(Level* l,float x_,float y_) : Actor(l,x_,y_,20,30) {
  val=0;
  dir=1;
  central_y=y;
  angle0=atan2((100+30.0),(470-30))+8*3.1415926535;
  angle=angle0;
#ifndef COMPILE_NO_SF
  texture=getGraphic("Fairy1");
  fairy.setOrigin(width/2,height/2);
  fairy.setScale(-1,1);
#endif
}

void Fairy::act() {
  if (val==-1) {}
  else if (val==0) {
    if (fabs(y-central_y)>=30)
      dir*=-1;
    y+=dir*1;
  }
  else if (val==1) {
    x+=3;
    y = central_y-(x+width)*(x+width)/400;
    fairy.setScale(-1,1);
    if (getY2()<0) {
      level->sendEvent(MISCE_2,this);
    }
    
  }
  else if (val==2) {
    y+=3;
    fairy.setScale(-1,1);
    if (getY1()>600)
      level->sendEvent(KILL,this);
    
  }
  else if (val==3) {
    angle-=3.1415926535/36;
    float mag = sqrt(130*130+470*470.0)/angle0;
    float r = mag*angle;
    x = r*cos(angle)+500;
    y = r*sin(angle)+100;
    if (angle<0) {
      central_y=y;
      val=0;
    }
    fairy.setScale(1,1);
  }
  else {
    std::cerr<<"FAIRY FAIL\n\n";
    throw "DO NOT HAVE THIS CODE";
  }
}

#ifndef COMPILE_NO_SF
void Fairy::render(sf::RenderWindow& window) {
  fairy.setTexture(texture);
  fairy.setPosition(getX1()+width,getY1()+height);
  window.draw(fairy);
}
#endif

void Fairy::turnOn(int i) {
  val=i;
  y=central_y;
}

void Fairy::kill() {
  val=-1;
  texture=getGraphic("GrayFairy");
  fairy.setRotation(-45);
}
