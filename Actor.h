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
	virtual ~Actor() {}
  virtual S_CODE getSave() {throw "ERROR: is not a save object\n";}

  virtual float getX1() const {return x;}
  virtual float getX2() const {return x+width;}
  virtual float getY1() const {return y;}
  virtual float getY2() const {return y+height;}

  virtual float getLastX1() const {return getX1();}
  virtual float getLastX2() const {return getX2();}
  virtual float getLastY1() const {return getY1();}
  virtual float getLastY2() const {return getY2();}
	
  friend bool operator==(const Actor& a1, const Actor& a2) {
    return a1.x==a2.x && a1.y == a2.y && a1.width==a2.width && a1.height==a2.height; 
  }
  virtual void setColor(int r, int g, int b) {}
  virtual void hitDetector(int dir) {}
  virtual std::string getMessage() {return "";}
  virtual int getVal() {return 0;}
  virtual bool doesPause() {return true;}
  virtual void act() = 0;

#ifndef COMPILE_NO_SF
  virtual void windowEvent(sf::Event& event) {}
  virtual void render(sf::RenderWindow& window) = 0;
#endif

protected:
  float x,y;
  float width,height;
  Level* level;
};

#endif
