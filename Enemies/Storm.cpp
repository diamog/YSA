#include "stdafx.h"
#include "Storm.h"
#include "../Extras/utilities.h"
#include <cmath>
Storm::Storm() : Actor(),Enemy() {

}

Storm::Storm(Level* l, float x_,float y_, You* yo) 
  : Actor(l,x_,y_,120,80), Enemy(l,x_,y_,120,80,yo,1) {
  ticks=15;
#ifndef COMPILE_NO_SF
  for (int i=0;i<25;i++) {
    sf::CircleShape cloud(20);
    cloud.setFillColor(sf::Color(120,120,120));
    cloud.setPosition(getX1()+getRand(0,width-40),getY1()+getRand(0,height-40));
    shape.push_back(cloud);
  }
#endif
  isDead=false;
}


void Storm::act() {
  
  Enemy::act();
  ticks++;
  int max_ticks = 60;
  int start_ticks= 57;
  float dist = 35;
  if (ticks>max_ticks) {
    ticks=start_ticks;
    float cx = x+width/2-dist/2;
    if (lines.size()%2==0)
      lines.push_back(Line(cx,cx,y+height/2+lines.size()*dist,
			   y+height/2+(lines.size())*dist));
    else
      lines.push_back(Line(cx+dist,cx+dist,y+height/2+lines.size()*dist,
			   y+height/2+(lines.size())*dist));
    
  }
  else if (lines.size()) {
    int index = lines.size()-1;
    float diff_dist = dist/(max_ticks-start_ticks);
    lines[index].p2.second+=diff_dist;
    if (lines.size()%2==0)
      lines[index].p2.first-=diff_dist;
    else
      lines[index].p2.first+=diff_dist;
  }
  if (lines.size()&&lines[lines.size()-1].p2.second>630)
    isDead=true;
  if (testLines(you,this)) {
    you->die();
  }
}

#ifndef COMPILE_NO_SF
void Storm::render(sf::RenderWindow& window) {
  for (size_t i=0;i<lines.size();i++) {
    Line l = lines[i];
    sf::Vertex line[] =
    {
      sf::Vertex(sf::Vector2f(l.p1.first, l.p1.second),sf::Color(200,200,0)),
      sf::Vertex(sf::Vector2f(l.p2.first, l.p2.second),sf::Color(200,200,0))
    };

    window.draw(line, 2, sf::Lines);
  }
  for (size_t i =0;i<shape.size();i++)
    window.draw(shape[i]);
  
}
#endif
