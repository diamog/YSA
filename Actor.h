#ifndef __ACTOR__H__
#define __ACTOR__H__

#ifndef COMPILE_NO_SF
#include <SFML/Graphics.hpp>
#endif

#include "Codes.h"
#include <iostream>

class Level;

class Actor {
 public:
  Actor();
  Actor(Level* l,float x_,float y_,float w,float h);

  virtual S_CODE getSave() {throw "ERROR: is not a save object\n";}

  virtual float getX1() const {return x;}
  virtual float getX2() const {return x+width;}
  virtual float getY1() const {return y;}
  virtual float getY2() const {return y+height;}

  friend bool operator==(const Actor& a1, const Actor& a2) {
    return a1.x==a2.x && a1.y == a2.y && a1.width==a2.width && a1.height==a2.height; 
  }

#ifndef COMPILE_NO_SF
  virtual void act(sf::Event& event) = 0;
  virtual void render(sf::RenderWindow& window) = 0;
#endif
 protected:
  float x,y;
  float width,height;
  Level* level;
};

#endif