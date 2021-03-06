#include "stdafx.h"
#include "Slope.h"
#include "../Extras/utilities.h"
#include <cassert>
#include <cmath>
Slope::Slope() : Actor(), Platform() {
  you = NULL;
  isLeft = isRight= isUp = isDown = true;
  disable=0;
}

Slope::Slope(Level* l, float x_,float y_,float w,float h,You* yo,
             float angle_in_degrees) : Actor(l,x_,y_,w,h), Platform(l,x_,y_,w,h,yo){
  disable=0;
  assert(fabs(angle_in_degrees)<90);
  angle=angle_in_degrees*3.14/180;
  
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(0,255,0));
  shape.setSize(sf::Vector2f(width,height));
  shape.setPosition(x,y);
  slope.setPointCount(3);
  slope.setFillColor(shape.getFillColor());
#endif
  isLeft = isRight= isUp = true;
  isDown=false;
  
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
    y2 -=width*sin(angle);
  lines.push_back(Line(x1,x2,y1,y2));
  return lines;
}
void Slope::act() {
  if (disable!=0)
    disable--;
#ifndef COMPILE_NO_SF
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    disable=10;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      disable=0;
#endif
  if (testLines(this,you)&&disable==0) {
    you->landSlope(this,angle);
  }
  else {
    Platform::act();
  }
}

#ifndef COMPILE_NO_SF
void Slope::render(sf::RenderWindow& window) {
  Platform::render(window);
  slope.setFillColor(shape.getFillColor());
  slope.setPoint(0,sf::Vector2f(getX1(),getY1()));
  slope.setPoint(1,sf::Vector2f(getX2(),getY1()));
  if (angle>0) {
    slope.setPoint(2,sf::Vector2f(getX2(),getY1()-width*sin(angle)));
  }
  else {
    slope.setPoint(2,sf::Vector2f(getX1(),getY1()+width*sin(angle)));
  }

  window.draw(slope);
}
#endif
