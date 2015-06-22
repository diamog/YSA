// First.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <iostream>
#ifndef COMPILE_NO_SF
#include <SFML/Graphics.hpp>
#endif
#include "You.h"
#include "Codes.h"
#include "Levels/Levels.h"


int main() {
  //Definition of Window
  int width = 700;
  int height = 600;
#ifndef COMPILE_NO_SF
  sf::RenderWindow window(sf::VideoMode(width, height), "YSA");
  window.setFramerateLimit(250);
#endif
  
  // Definition of you
  bool* isDead = new bool;
	*isDead = false;
  You* you = new You(200,height-400.0f,20,20,isDead);
  Level* level = loadLevel(you, you->getSave());
  
#ifndef COMPILE_NO_SF
  while (window.isOpen()) {
    sf::Event event;
    if (*isDead==false) {
			you->act(event);
      level->act(event);
		}
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
	      window.close();
			if (event.type == sf::Event::KeyPressed&&event.key.code ==sf::Keyboard::R) {
				delete level;
				level = loadLevel(you,you->getSave());
				*isDead=false;
				you->reload();
			}
			if (event.type == sf::Event::KeyPressed&&event.key.code ==sf::Keyboard::P) {
				you->print();
			}
    }
		L_CODE next_level;
		ENT_CODE ent;
		if (level->isChangeRoom(next_level,ent)) {
			Level* temp = level;
			level = makeLevel(you,next_level,ent);
			delete temp;
		}
    window.clear();
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

