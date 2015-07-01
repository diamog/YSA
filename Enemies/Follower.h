#include "Enemy.h"
#include <list>
#include <utility>
#ifndef __FOLLOWER__H__
#define __FOLLOWER__H__

class Follower : public Enemy{
 public:
  Follower();
  Follower(Level* l, float x_,float y_,You* yo, 
           int num,std::vector<Actor*>* actors,
	   std::list<std::pair<float,float> > start_pos=std::list<std::pair<float,float> >(),std::list<float> angs=std::list<float>());
  
  void act();

#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
 protected:
  std::vector<Actor*>* level_actors;
  std::list<std::pair<float,float> > pos;
  std::list<float> angles;
  int alpha;
  int num_left;
#ifndef COMPILE_NO_SF
  sf::RectangleShape shape;
#endif
  
};

#endif
