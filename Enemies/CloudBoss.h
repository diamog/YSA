#include "Enemy.h"
#include "CBullet.h"
#include "Cloud.h"
#include "SmallEye.h"
#include "Storm.h"
#include "../Switables/RedSwitch.h"
#ifndef __CLOUDBOSS1__H__
#define __CLOUDBOSS1__H__

class CloudBoss1 : public Enemy {
 public:
  CloudBoss1();
  CloudBoss1(Level* l, You* yo, SmallEye* e);
  ~CloudBoss1();
  void act();

  bool isPart2() {return !clouds.size();}
  std::vector<Circle> getCircles();
  void start() {move=true;}
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
 protected:
  std::vector<Cloud*> clouds;
  RedSwitch* eye;
  bool move;
  float ticks;
  int max_ticks;
  float rate;
#ifndef COMPILE_NO_SF
  sf::CircleShape top;
  sf::CircleShape left;
  sf::CircleShape right;
  sf::RectangleShape nose;
#endif
  float base_y;
  float angle;
  int dir;
  int diry;
  std::vector<Storm*> storms;
  std::vector<CBullet*> bullets;
};

class CloudBoss2 : public Enemy {
 public:
  CloudBoss2();
  CloudBoss2(Level* l, You* yo);
  ~CloudBoss2();

  std::vector<Circle> getCircles();
  RedSwitch* kill() {part = 5;return eye;}
  void act();
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
  int getAlpha() {if (part==5) return alpha; else return 255;}
 protected:
  RedSwitch* eye;
  float ticks;
  int max_ticks;
  float rate;
  int part;
#ifndef COMPILE_NO_SF
  sf::CircleShape top;
  sf::CircleShape left;
  sf::CircleShape right;
  sf::RectangleShape nose;
#endif
  bool isHit;
  int hit_ticks;
  float bullet_tick;
  int wind_dir;
  int wind_tick;
  int storm_ticks;
  int alpha;
  std::vector<Storm*> storms;
  std::vector<CBullet*> bullets;
};


#endif
