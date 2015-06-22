#ifndef __BULLET__H__
#define __BULLET__H__

#include "Mover.h"

class Level;

class Bullet : public Mover {
public:
 Bullet() : Mover(), Actor() {type="";}
  Bullet(Level* l,float x_, float y_, float w, float h,std::string t)
    : Mover(l,x_,y_,w,h), Actor(l,x_,y_,w,h) {type=t;
#ifndef COMPILE_NO_SF
    shape.setRadius(width/2);
    shape.setFillColor(sf::Color(255,255,0));
#endif
}
  std::string getType() {return type;}
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window) {
    shape.setPosition(x,y);
    window.draw(shape);
  }
#endif
protected:
  std::string type;
#ifndef COMPILE_NO_SF
  sf::CircleShape shape;
#endif
};

#endif
