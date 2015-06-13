// First.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "You.h"
#include "Codes.h"
#include "Levels.h"

;
int main()
{
  //Definition of Window
  int width=700;
  int height = 600;
  sf::RenderWindow window(sf::VideoMode(width, height), "SFML works...finally");
  window.setFramerateLimit(300);

  // Definition of you
  You* you = new You(100,height-100.0f,20,20,width,height);
  Level* level = new Level1(you,0,0,MISC_1);

  while (window.isOpen()) {
    sf::Event event;
    you->act();
    level->act();
    while (window.pollEvent(event))
    {
	  if (event.type == sf::Event::Closed)
	    window.close();
    }
		
    window.clear();
    you->render(window);
    level->render(window);		
    window.display();
  }
  delete you;
  delete level;
  return 0;
}

