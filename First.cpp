// First.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <iostream>
#include <fstream>
#ifndef COMPILE_NO_SF
#include <SFML/Graphics.hpp>
#endif
#include "You.h"
#include "Codes.h"
#include "Levels/Levels.h"
#include <cstdlib>
#include <time.h>
#include "Extras/Line.h"
#include "Extras/utilities.h"

int main() {
  
  srand(time(NULL));
  //Definition of Window
  int width = 700;
  int height = 600;
#ifndef COMPILE_NO_SF
  sf::RenderWindow window(sf::VideoMode(width, height), "YSA Version 0.2.dev");
  window.setFramerateLimit(60);
#endif
  
  // Definition of you
  bool* isDead = new bool;
  *isDead = false;
  You* you = new You(200,height-400.0f,20,20,isDead);
  std::ifstream in_str(".8e91q02a38x74f29d302s");
  if (in_str)
    you->load(in_str);
  Level* level = loadLevel(you, you->getSave());
  
#ifndef COMPILE_NO_SF
  while (window.isOpen()) {
    sf::Event event;
    if (!you->isPause()) {
      if (*isDead==false) {
        if (!you->isPauseM())
          you->act();
      }
      level->act();
    }
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::KeyPressed) {
        if(event.key.code ==sf::Keyboard::R&&!you->isPause()&& !you->isPauseM()) {
          *isDead=false;
          you->reload();
	  delete level;
          level = loadLevel(you,you->getSave());
          
        }
        if (event.key.code ==sf::Keyboard::O) {
          you->print();
        }
        if (event.key.code ==sf::Keyboard::P) {
          you->pause();
        }
	if (event.key.code == sf::Keyboard::Num0) {
	  you->save(GAME_START);
	}
        if (event.key.code == sf::Keyboard::Num1) {
          you->save(ROOM_1);
        }
        if (event.key.code==sf::Keyboard::Num2) {
          you->save(CROSS_ROADS);
          you->beatBoss1();
        }
        if (event.key.code==sf::Keyboard::Num3) {
          you->save(ROOM_3);
        }

      }
      level->windowEvent(event);
      
    }
    L_CODE next_level;
    ENT_CODE ent;
    if (level->isChangeRoom(next_level,ent)) {
      delete level;
      level = makeLevel(you,next_level,ent);
    }
    if (level->isBoss())
      window.clear();
    else
      window.clear(sf::Color(100,100,100));
    level->render(window);
    you->render(window);
    window.display();
  }
#endif
  delete level;
  delete you;
  delete isDead;
  return 0;
}

