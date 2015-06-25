#ifndef __Crystal__H__
#define __Crystal__H__

#include "Collectable.h"


class Crystal : public Collectable {
 public:
  Crystal();
  Crystal(Level* l,float x_, float y_, float w, float h, You* yo, std::string t);

  std::string getMessage() {return type;}
  void activate();
	void setPosition(float x_, float y_) {Actor::setPosition(x_,y_);shape.setPosition(x,y);}
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
  int getVal() {return color;}
  
private:
  std::string type;
  int color;
#ifndef COMPILE_NO_SF
  sf::CircleShape shape;
#endif
};

#endif
