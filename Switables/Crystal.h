#ifndef __Crystal__H__
#define __Crystal__H__

#include "Collectable.h"


class Crystal : public Collectable {
 public:
  Crystal();
  Crystal(Level* l,float x_, float y_, float w, float h, You* yo, std::string t);


#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif

  //void activate();
  
 private:
  std::string type;

};

#endif
