#ifndef __YOU__H__
#define __YOU__H__

#include "Mover.h"

class You  : public Mover{
public:
  You();
  You(float x_, float y, float w, float h, int screenW, int screenH);

#ifndef COMPILE_NO_SF
  void act(sf::Event& event);
  void render(sf::RenderWindow& window);
#endif

  S_CODE getSave() {return savepoint;}

  void land(float y_,float x1, float x2);
  void ceiling(float y_);
  void hitLeftWall(float x_,float y1, float y2,bool isKick=false);
  void hitRightWall(float x_,float y1, float y2,bool isKick=false);
  
  void save(S_CODE s);
  void die();
 private:
  int sWidth,sHeight;
  S_CODE savepoint;
  int deaths;
#ifndef COMPILE_NO_SF
  sf::RectangleShape shape;
#endif
  int isJump;
  float dx;
  float dy;
  float downLimit;
  float grav;
  float platx1,platx2;
  bool* isDead;
};

#endif
