#ifndef __PLATFORM__H__
#define __PLATFORM__H__

#include "../You.h"
#include "../Actor.h"

class Platform : virtual public Actor {
 public:
  Platform();
  Platform(Level* l, float x_,float y_,float w,float h,You* yo);

  void act();
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif

protected:
  bool kickLeft,kickRight;
  bool isUp,isLeft,isRight,isDown;
  You* you;
#ifndef COMPILE_NO_SF
  sf::RectangleShape shape;
#endif
};

#endif
