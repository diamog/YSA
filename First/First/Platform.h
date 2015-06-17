#ifndef __PLATFORM__H__
#define __PLATFORM__H__

#include "You.h"
#include "Actor.h"

class Platform : public Actor {
 public:
  Platform();
  Platform(Level* l, float x_,float y_,float w,float h,You* yo);

#ifndef COMPILE_NO_SF
  void act(sf::Event& event);
  void render(sf::RenderWindow& window);
#endif
 private:
	
  bool isUp,isLeft,isRight,isDown;
  You* you;
#ifndef COMPILE_NO_SF
  sf::RectangleShape shape;
#endif
};

#endif
