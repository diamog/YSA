#include "Enemy.h"
#include "PBullet.h"
#ifndef __GHOSTHEAD__H__
#define __GHOSTHEAD__H__

class PGhost : public Enemy{
 public:
  PGhost();
  PGhost(Level* l, bool isLeft, You* yo);

  void act();

#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif

protected:
  unsigned int ticks;
#ifndef COMPILE_NO_SF
  sf::Texture texture;
  sf::Sprite head;
#endif
  std::vector<PBullet*> bullets;
};

#endif
