#ifndef __SLOPE__H__
#define __SLOPE__H__

#include "Platform.h"

class Slope : public Platform {
 public:
  Slope();
  Slope(Level* l, float x_,float y_,float w,float h,You* yo,
        float angle_in_degrees);

  void act();
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
  std::vector<Line> getLines();
protected:
  float angle;
};

#endif
