#ifndef __BULLET__H__
#define __BULLET__H__

#include "Mover.h"

class Level;

class Bullet : public Mover {
public:
  Bullet();
  Bullet(Level* l,float x_, float y_, float w, float h,std::string t);
  std::string getType() {return type;}
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
protected:
  std::string type;
#ifndef COMPILE_NO_SF
  sf::CircleShape shape;
#endif
};

#endif
