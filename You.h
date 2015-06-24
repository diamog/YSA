#ifndef __YOU__H__
#define __YOU__H__

#include "Mover.h"
#include "Bullet.h"
#include <vector>
#include <set>
class Level;

class You  : public Mover{
public:
  You();
  You(float x_, float y, float w, float h, bool* isD);
  ~You();
  float getPlatX1() {return platx1;}	
  float getPlatX2() {return platx2;}		
	
  void setPosition(float x_, float y_);
#ifndef COMPILE_NO_SF
  void act(sf::Event& event);
  void render(sf::RenderWindow& window);
#endif

  void pause() {isPaused=!isPaused;}
  void messagePause() {isMessagePaused=!isMessagePaused;}
  bool isPause() {return isPaused;}
  bool isPauseM() {return isMessagePaused;}
  S_CODE getSave() {return savepoint;}
  bool hasExtra(L_CODE l) {return extras.find(l)!=extras.end();}
  void getExtra(L_CODE l) {extras.insert(l);}
  void land(float y_,float x1, float x2);
  void ceiling(float y_);
  void hitLeftWall(float x_,float y1, float y2,bool isKick=false);
  void hitRightWall(float x_,float y1, float y2,bool isKick=false);
  
  void save(S_CODE s);
  void die();
  void reload();
  void addBullet(Bullet* b) {bullets.push_back(b);}
  const std::vector<Bullet*>& getBullets() {return bullets;}
  void removeBullet(int i) {delete bullets[i];bullets.erase(bullets.begin()+i);};	
    
  void print();
 private:
  bool isPaused;
  bool isMessagePaused;
  S_CODE savepoint;
  int deaths;
#ifndef COMPILE_NO_SF
  sf::RectangleShape shape;
  sf::Font font;
  sf::Text you_died;
  sf::Text text_restart;
#endif
  int isJump;
  float dx;
  float dy;
  float downLimit;
  float grav;
  float platx1,platx2;
  bool* isDead;
  int alpha;
  std::vector<Bullet*> bullets;
  std::set<L_CODE> extras;
  
};

#endif
