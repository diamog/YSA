#include "Enemy.h"

#ifndef __COLORBOSS__H__
#define __COLORBOSS__H__


class ColorBoss : public Enemy{
 public:
  ColorBoss();
  ColorBoss(Level* l, float x_,float y_,float w,float h, You* yo);
  
#ifndef COMPILE_NO_SF
  void act(sf::Event& event);
  void render(sf::RenderWindow& window);
#endif
  bool isAlive() {return r>0||g>0||b>0;}
  int getR() {return r;}
  int getG() {return g;}
  int getB() {return b;}
  void hit();
  void color_hit(int& color);

 protected:
  float vx,vy;
  float accel;
  int  r,g,b;
  int hit_amount;
#ifndef COMPILE_NO_SF
	sf::CircleShape shape;
#endif
};

#endif
