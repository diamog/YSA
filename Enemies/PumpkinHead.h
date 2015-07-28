#include "Enemy.h"
#include "PBullet.h"
#include "../Platforms/Stem.h"
#ifndef __PUMPKINHEAD__H__
#define __PUMPKINHEAD__H__

class PumpkinHead : public Enemy{
 public:
  PumpkinHead();
  PumpkinHead(Level* l, float x_, You* yo, int health);
  ~PumpkinHead();

  void act();
  virtual void hit();
  int getNumStems() {return numstems;}
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
  void turnOff() {isOn=false;}
  void connect(PumpkinHead* other) {other_stems=&(other->stems);}
 protected:
  unsigned int ticks;
  int phase;
  int tempnumstems;
  int numstems;
#ifndef COMPILE_NO_SF
  sf::Texture texture;
  sf::Sprite head;
  /* sf::CircleShape shape; */
  /* sf::CircleShape eye; */
#endif
  int stem_height;
  float eyex;
  std::vector<PBullet*> bullets;
  std::vector<Stem*> stems;
  std::vector<Stem*>* other_stems;
  bool isOn;
};

#endif
