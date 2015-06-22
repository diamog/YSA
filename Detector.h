#ifndef __DETECTOR__H__
#define __DETECTOR__H__


#include "Actor.h"

class Detector : public Actor{
 public:
  Detector();
  Detector(Level* l,float x_,float y_,float w,float h,std::vector<Actor*>* acts);

  virtual S_CODE getSave() {throw "ERROR: is not a save object\n";}

	
#ifndef COMPILE_NO_SF
  void act(sf::Event& event);
  void render(sf::RenderWindow& window);
#endif
 protected:
	 std::vector<Actor*>* actors;
};

#endif
