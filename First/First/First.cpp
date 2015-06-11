// First.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "You.h"
#include "Platform.h"


int main()
{
	//Definition of Window
	int width=700;
	int height = 600;
	sf::RenderWindow window(sf::VideoMode(width, height), "SFML works...finally");

	// Definition of you
	You you(100,height-100,20,20,width,height);
	int numPlats = 4;
	Platform* plats = new Platform[numPlats];
	Platform plat(0,height-30,width,30,&you);
	plats[0] = plat;
	Platform plat2(0,0,30,height-30,&you);
	plats[1]=plat2;
	Platform plat3(width-30,0,30,height-30,&you);
	plats[2] = plat3;
	Platform plat4(width-130,height-100,100,25,&you);
	plats[3] = plat4;
	window.setFramerateLimit(300);
    while (window.isOpen())
    {
		
		sf::Event event;
		you.act();
		for (int i=0;i<numPlats;i++)
			plats[i].act();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();
		you.render(window);
		for (int i=0;i<numPlats;i++)
			plats[i].render(window);
		
		window.display();
    }

    return 0;
}

