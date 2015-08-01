#ifndef __BIGEYE__H__
#define __BIGEYE__H__

#include <vector>
#include "../Enemies/SmallEye.h"
#include "../Detector.h"

class BigEye : public Detector{
 public:
  BigEye();
  BigEye(Level* l,float x_,float y_,EVE_CODE eve_, SmallEye* e );

  void act();
  bool isOn() {return isHit;}
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
 protected:
  bool isHit;
  EVE_CODE eve;
  SmallEye* eye;
  int dir;
  sf::CircleShape shape2;

 private:
  bool isInside();
};

#endif
