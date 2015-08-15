#include "Enemy.h"
#include "../Extras/Arc.h"

#ifndef __COLORBOSS__H__
#define __COLORBOSS__H__

/* Difficulty Notes
   damage per color reduces per diff
   movement speed increases per diff
   hard color bullets do not move
*/

class ColorBoss : public Enemy{
 public:
  ColorBoss();
  ColorBoss(Level* l, float x_,float y_,float w,float h, You* yo);

  DIFF_CODE getDifficulty() {return you->getDifficulty();}
  void act();  
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif
  bool isAlive() {return r>0||g>0||b>0;}
  int getR() {return r;}
  int getG() {return g;}
  int getB() {return b;}
  void hit();
  void color_hit(int& color);

 protected:
  bool hasMessaged;
  float vx,vy;
  float accel;
  int  r,g,b;
  int hit_amount;
#ifndef COMPILE_NO_SF
  Arc shape;
  float ang;
  int ang_dir;
  //sf::CircleShape shape;
#endif
  bool isRed,isGreen,isBlue;
  int target;
  bool isOCD;
};

#endif
