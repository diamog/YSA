#ifndef __STEM__H__
#define __STEM__H__

#include "Platform.h"

class Stem : public Platform {
 public:
  Stem();
  Stem(Level* l, float x_,float y_,float cx_,float w,float h,You* yo, int d);

  void act();
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
  void setPumpDir(int d);
  void setDir(int d) {dir=d;}
  void setDeath() {isDead=true;}
  bool getDead() {return isDead;}
 private:
  int dir;
  float cx;
  bool isDead;
  sf::Texture vine;
  sf::Texture wiltedvine;
  sf::Sprite stem;
};

#endif
