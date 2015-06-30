#include "stdafx.h"
#include "Slope.h"
#include "../Extras/utilities.h"
#include <cassert>
#include <cmath>
Slope::Slope() : Actor() {
  you = NULL;
  isLeft = isRight= isUp = isDown = true;

}

Slope::Slope(Level* l, float x_,float y_,float w,float h,You* yo,
             float angle_in_degrees) : Platform(l,x_,y_,w,h,yo), Actor(l,x_,y_,w,h){
  assert(fabs(angle_in_degrees)<90);
  angle=angle_in_degrees*3.14/180;
  
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(0,255,0));
  shape.setSize(sf::Vector2f(width,height));
  shape.setPosition(x,y);
#endif
  isLeft = isRight= isDown = true;
  isUp=false;
}

std::vector<Line> Slope::getLines() {
  std::vector<Line> lines;
  float x1,y1,x2,y2;
  x1 = getX1();
  y1 = getY1();
  x2 = getX2();
  y2 = getY1();
  if (angle<0)
    y1 +=width*sin(angle);
  else
    y2+=width*sin(angle);
  lines.push_back(Line(x1,x2,y1,y2));
  return lines;
}
void Slope::act() {
  if (testLines(this,you)) {
    you->landSlope(getY1(),getX1(),getX2(),angle);
  }
  else {
    Platform::act();
  }
}

#ifndef COMPILE_NO_SF
void Slope::render(sf::RenderWindow& window) {
  
  window.draw(shape);
}
#endif
