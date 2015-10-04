#ifndef __CATBULLET__H__
#define __CATBULLET__H__

#include <cmath>
#include "../Enemies/Death.h"
#include "../Bullet.h"
#include "../Extras/utilities.h"
#include "../Platforms/ThinPlat.h"

class CatBullet : public Bullet, public Death {
public:
  CatBullet();
  CatBullet(Level* l,float x_, float y_,float rad,You* yo, 
	  std::vector<ThinPlat*>* p);
  void act();
  bool isGone() const {return isDead;}

  void render(sf::RenderWindow& window);
protected:
  std::vector<ThinPlat*>* plats;
  float angle;
  float vel;
  bool isDead;
  float tick;
  int num_circ;
  sf::CircleShape track[6];
};

#endif
