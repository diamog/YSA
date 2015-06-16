#ifndef __YOU__H__
#define __YOU__H__

#include "Mover.h"

class You  : public Mover{
public:
  You();
  You(float x_, float y, float w, float h, int screenW, int screenH);

  void act();
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif

  void land(float y_,float x1, float x2);
  void ceiling(float y_);
  void hitLeftWall(float x_,float y1, float y2,bool isKick=false);
  void hitRightWall(float x_,float y1, float y2,bool isKick=false);
 private:
  int sWidth,sHeight;
#ifndef COMPILE_NO_SF
  sf::RectangleShape shape;
#endif
  int isJump;
  float dx;
  float dy;
  float downLimit;
  float grav;
  float platx1,platx2;
	
};

#endif
