#include "Enemy.h"
#include <list>
#include <utilities.h>
#ifndef __FOLLOWER__H__
#define __FOLLOWER__H__

class Follower : public Enemy{
 public:
  Follower();
  Follower(Level* l, float x_,float y_,You* yo, 
	   int num,std::vector<Actor*>* actors);
  
  void act();

#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
 protected:
  std::vector<Actor*>* level_actors;
  std::list<std::pair<float,float> > pos;
  int alpha;
  int num_left;

  
};

#endif
