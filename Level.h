#ifndef COMPILE_NO_SF
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#endif
#include <vector>
#include "Actor.h"
#include "Detector.h"
#include "Codes.h"
#include "You.h"
#include <iostream>

#ifndef __LEVEL_H__
#define __LEVEL_H__

class Extra;

class Level {
 public:
  Level();
  Level(You* yo);
  virtual ~Level() {destroy();}

  float getX() {return x;}
  float getY() {return y;}
  float getWidth() {return width;}
  float getHeight() {return height;}
  virtual void act();
  virtual void resetEye() {}
  bool isBoss() {return isboss;}

#ifndef COMPILE_NO_SF
  void windowEvent(sf::Event& event); 
  virtual void render(sf::RenderWindow& window);
#endif
  virtual void sendEvent(EVE_CODE eve, Actor* sender);
  void destroy();
  void warp() {isWarp=true;}
  virtual bool isChangeRoom(L_CODE& next_level, ENT_CODE& ent_type);
  void remove(Actor* actor);  
  
protected:
  bool isboss;
  void setup();

  void centerLevel();
  virtual void makePlatforms() {};
  virtual void makeEnemies() {};
  virtual void makeCollectables() {};
  virtual void makeSwitches() {};
  virtual void makeDetectors() {};
  void buildHint(float x, float y, int code, std::string m);
  Extra* buildExtra(float x,float y);
  int buildCoin(float x,float y,EVE_CODE eve);
  void buildSave(float x, float y, SAVE_CODE s,DIFF_CODE d);

  float x,y;
  float width,height;
  std::vector<Actor*> actors;
  std::vector<Actor*> actors2; //to be sent to detectors
  std::vector<Detector*> detectors;
  You* you;
  L_CODE me;
  bool canMove;
  bool isWarp;
  sf::Music* save_sfx;
};

#endif
