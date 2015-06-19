// First.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <iostream>
#ifndef COMPILE_NO_SF
#include <SFML/Graphics.hpp>
#endif
#include "You.h"
#include "Codes.h"
#include "Levels.h"


int main() {
  //Definition of Window
  int width = 700;
  int height = 600;
#ifndef COMPILE_NO_SF
  sf::RenderWindow window(sf::VideoMode(width, height), "YSA");
  window.setFramerateLimit(300);
#endif
  
  // Definition of you
  bool* isDead = new bool;
  *isDead = false;
  You* you = new You(100,height-100.0f,20,20,width,height);
  S_CODE s = GAME_START;
  Level* level = loadLevel(you, s);
  
#ifndef COMPILE_NO_SF
  while (window.isOpen()) {
    sf::Event event;
    you->act(event);
    if (*isDead==false)
      level->act(event);
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
	window.close();
      /*if r key is hit {
	level->destroy();
	delete level;
	level = loadLevel(you,you->getSave());
      }
      */
    }
		
    window.clear();
    you->render(window);
    level->render(window);		
    window.display();
  }
#endif
  delete level;
  delete you;
  delete isDead;
  return 0;
}

