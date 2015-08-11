#ifndef __YOU__H__
#define __YOU__H__
#include "./Extras/utilities.h"
#include "Mover.h"
#include "Bullet.h"
#include <vector>
#include <set>
class Level;
class Platform;

class You  : public Mover{
public:
  You();
  You(float x_, float y, float w, float h, bool* isD);
  ~You();

  Platform* getPlat() const {return plat;}
  std::vector<Line> getLines();
#ifndef COMPILE_NO_SF
  float getAngle() {return shape.getRotation();}
#else
  float getAngle() {return 0;}
#endif

  void setFall(float max=0.0);
  void setPosition(float x_, float y_,bool keepLast=false);
  void act();
#ifndef COMPILE_NO_SF
  void render(sf::RenderWindow& window);
#endif

  void pause() {isPaused=!isPaused;}
  void messagePause() {isMessagePaused=!isMessagePaused;}
  void controlPause();
  bool isPause() {return isPaused;}
  bool isPauseM() {return isMessagePaused;}
  bool isPauseC() {return isControlPaused;}
  
  S_CODE getSave() {return savepoint;}
  bool hasExtra(L_CODE l) {return extras.find(l)!=extras.end()||temp_extras.find(l)!=temp_extras.end();}
  void getExtra(L_CODE l) {temp_extras.insert(l);}
  bool hasHint(int i) {return hints.find(i)!=hints.end();}
  void getHint(int i) {hints.insert(i);}
  

  void land(Platform* p);
  void landSlope(Platform* p,float angle);
  void ceiling(float y_);
  void hitLeftWall(float x_,bool isKick=false);
  void hitRightWall(float x_,bool isKick=false);

  void warp();
  void save(S_CODE s);
  void die();
  bool getDead() {return *isDead;}
  void reload();
  void addBullet(Bullet* b) {bullets.push_back(b);}
  const std::vector<Bullet*>& getBullets() {return bullets;}
  void removeBullet(int i) {delete bullets[i];bullets.erase(bullets.begin()+i);};	
    

  bool boss1() {return isColor;}
  bool boss2() {return isCloud;}
  bool boss2Half() {return isCloudHalf;}
  bool boss3() {return isPump;}
  bool boss3Half() {return isPumpHalf;}
  bool boss4() {return isCat;}
  bool boss5() {return isFire;}
  bool boss6() {return isColor2;}
  void beatBoss1() {isColor=true;buildAchievement(BEAT_COLOR);}
  void beatBoss2() {isCloud=true;}
  void beatBoss2Half() {isCloudHalf=true;}
  void beatBoss3() {isPump=true;}
  void beatBoss3Half() {isPumpHalf=true;}
  void beatBoss4() {isCat=true;}
  void beatBoss5() {isFire=true;}
  void beatBoss6() {isColor2=true;}

  void antiGravity() {isAntiGrav=!isAntiGrav;}
  bool isAntiGravity() {return isAntiGrav;}
  bool hasSplit() {return hasEnterSplit;}
  void enterSplit() {hasEnterSplit=true;}
  void load(std::string file_name);
  void save();
  void print();
protected:
  bool isPaused;
  bool isMessagePaused;
  bool isControlPaused;
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
  Platform* plat;
  bool* isDead;
  int alpha;
  std::vector<Bullet*> bullets;
  std::set<L_CODE> extras;
  std::set<L_CODE> temp_extras;
  std::set<int> hints;
  bool isColor,isCloud,isCloudHalf,isPump,isPumpHalf,isCat,isFire,isColor2;
  bool isKickLeft,isKickRight;
  bool hasEnterSplit;
  bool isAntiGrav;

  std::string file;
};

#endif
