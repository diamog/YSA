#include "Enemy.h"
#ifndef __STORM__H__
#define __STORM__H__

class Storm : public Enemy {
 public:
  Storm();
  Storm(Level* l, float x_,float y_, You* yo);
  
  std::vector<Line> getLines() {return lines;}

  void act();
  bool getDead() const {return isDead;}
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
 protected:
  int ticks;
  std::vector<Line> lines;
#ifndef COMPILE_NO_SF
  std::vector<sf::CircleShape> shape;
#endif
  bool isDead;
};

#endif
