#include "Enemy.h"

#ifndef __SMALLEYE__H__
#define __SMALLEYE__H__

class SmallEye : public Enemy {
 public:
  SmallEye();
  SmallEye(Level* l, float x_,float y_, You* yo,int d);
  
  void act();
  void start(float v=0.5) {isOn=true;vel=v;}
  void stop() {isOn=false;}
  void hitDetector(int adir);
  void setReset(float x_,float y_) {resetx = x_;resety=y_;}
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
  void reset();
  void setDir(int d) {dir=d;orig_dir=d;}
 protected:
  bool isOn;
  int orig_dir;
  int dir;
  float vel;
  float accel;
  float resetx,resety;
#ifndef COMPILE_NO_SF
  sf::CircleShape shape;
#endif
	int count;
};

#endif
