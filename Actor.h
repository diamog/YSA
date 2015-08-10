#ifndef __ACTOR__H__
#define __ACTOR__H__

#ifndef COMPILE_NO_SF
#include <SFML/Graphics.hpp>
#endif
#include "Extras/Line.h"
#include "Extras/Circle.h"
#include "Codes.h"
#include <stdexcept>
#include <iostream>
#include <vector>

class Reverser;
class Level;

class Actor {
 public:
  Actor();
  Actor(Level* l,float x_,float y_,float w,float h);
  virtual ~Actor() {}
  virtual S_CODE getSave() {throw "ERROR: is not a save object\n";}

  virtual float getX1() const;
  virtual float getX2() const;
  virtual float getY1() const;
  virtual float getY2() const;
  virtual float getWidth() const {return width;}
  virtual float getHeight() const {return height;}
  virtual void setWidth(float w) {width=w;}
  virtual void setHeight(float h) {height = h;}
  virtual void shiftX(float dx) {x+=dx;}
  virtual void shiftY(float dy) {y+=dy;}
  virtual float getLastX1() const {return getX1();}
  virtual float getLastX2() const {return getX2();}
  virtual float getLastY1() const {return getY1();}
  virtual float getLastY2() const {return getY2();}
  virtual std::vector<Line> getLines() 
    {throw std::runtime_error("NOT IMPLEMENTED");}
  virtual std::vector<Circle> getCircles() 
    {throw std::runtime_error("NOT IMPLEMENTED");}
	
  friend bool operator==(const Actor& a1, const Actor& a2) {
    return a1.x==a2.x && a1.y == a2.y && a1.width==a2.width && a1.height==a2.height; 
  }
  virtual void setPosition(float x_, float y_,bool keepLast=false) {x=x_;y=y_;}
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
  void addReverser(Reverser* r) {rev=r;}
protected:
  float x,y;
  float width,height;
  Level* level;
  Reverser* rev;
  float frame_diff;
};

#endif
