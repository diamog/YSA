#ifndef __DETECTOR__H__
#define __DETECTOR__H__

#include <vector>
#include "Actor.h"

class Detector : public Actor{
 public:
  Detector();
  Detector(Level* l,float x_,float y_,float w,float h,std::vector<Actor*>* acts);

  virtual S_CODE getSave() {throw "ERROR: is not a save object\n";}

  void act();
  	
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
 protected:
  std::vector<Actor*>* actors;
};

#endif
