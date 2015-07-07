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
  std::vector<Line> getLines();
#ifndef COMPILE_NO_SF
  float getAngle() {return shape.getRotation();}
#else
  float getAngle() {return 0;}
#endif

  void setFall() {if (isJump==0) isJump=2;}
  void setPosition(float x_, float y_,bool keepLast=false);
  void act();
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif

  void pause() {isPaused=!isPaused;}
  void messagePause() {isMessagePaused=!isMessagePaused;}
  bool isPause() {return isPaused;}
  bool isPauseM() {return isMessagePaused;}
  
  S_CODE getSave() {return savepoint;}
  bool hasExtra(L_CODE l) {return extras.find(l)!=extras.end();}
  void getExtra(L_CODE l) {extras.insert(l);}
  bool hasHint(int i) {return hints.find(i)!=hints.end();}
  void getHint(int i) {hints.insert(i);}
  

  void land(float y_,float x1, float x2);
  void landSlope(float y_,float x1, float x2, float angle);
  void ceiling(float y_);
  void hitLeftWall(float x_,bool isKick=false);
  void hitRightWall(float x_,bool isKick=false);
  
  void save(S_CODE s);
  void die();
  void reload();
  void addBullet(Bullet* b) {bullets.push_back(b);}
  const std::vector<Bullet*>& getBullets() {return bullets;}
  void removeBullet(int i) {delete bullets[i];bullets.erase(bullets.begin()+i);};	
    

  bool boss1() {return isColor;}
  bool boss2() {return isCloud;}
  bool boss3() {return isPump;}
  bool boss4() {return isCat;}
  bool boss5() {return isFire;}
  bool boss6() {return isColor2;}
  void beatBoss1() {isColor=true;}
  void beatBoss2() {isCloud=true;}
  void beatBoss3() {isPump=true;}
  void beatBoss4() {isCat=true;}
  void beatBoss5() {isFire=true;}
  void beatBoss6() {isColor2=true;}

  void load(std::istream& in_str);
  void save(std::ostream& out_str);
  void print();
protected:
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
  float vx;
  float dx;
  float dy;
  float downLimit;
  float grav;
  float platx1,platx2;
  float base_y;
  bool* isDead;
  int alpha;
  std::vector<Bullet*> bullets;
  std::set<L_CODE> extras;
  std::set<int> hints;
  bool isColor,isCloud,isPump,isCat,isFire,isColor2;
  bool isKickLeft,isKickRight;
};

#endif
