#include "Enemy.h"
#include "../Extras/Arc.h"
#include "../Extras/Circle.h"
#include "../Bullet.h"
#include "../Platforms/ThinPlat.h"
#ifndef __CATBOSS__H__
#define __CATBOSS__H__


class CatBoss : public Enemy{
 public:
  CatBoss();
  CatBoss(Level* l, You* yo);

  DIFF_CODE getDifficulty() {return you->getDifficulty();}
  void act();  

  std::vector<Circle> getCircles();

#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
  void hit();
 protected:
  int maxhp;
#ifndef COMPILE_NO_SF
  sf::RectangleShape cat_head;
  sf::CircleShape spawner;
  Arc shape;
  float ang;
  int ang_dir;
#endif
  float ticks;
  int part;
  int col;
  int skip;
  int numRockets;
  int dir;
  bool isHit;
  int ticks2;
  std::vector<Bullet*> bullets;
  std::vector<ThinPlat*> plats;
};

#endif
